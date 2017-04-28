#include "coder.h"
/*
uint8_t getBytes(uint32_t digit)
{
    uint8_t bytes = (digit >> 7) ? MaxCodeLength : 1;
    if (bytes != 1) {
        uint8_t mask = pow(2, 8 - (MaxCodeLength + 1)) - 1;
        if (digit >= (((mask - ((uint8_t)pow(2, 8 - (MaxCodeLength + 2)) - 1)) << ((MaxCodeLength - 1) * 6 + 1)))) {
            
			return (MaxCodeLength + 1);
        }
        int8_t offset = 0;
        if (((digit >> ((MaxCodeLength - 1) * 6)) & mask) == 0) {
            --bytes;
            for (offset = (MaxCodeLength - 2) * 6; offset >= 0; offset -= 6) {
                if (((digit >> offset) & 0x3F) != 0) {
                    if (((digit >> offset) & 0x3F) >= (0x20 >> (bytes - 2))) {
                        ++bytes;
                    }
                    break;
                } else {
                    --bytes;
                }
            }
        }
    }
    
    return bytes;
}
*/
int encode(uint32_t code_point, CodeUnits *code_units)
{
    if (code_units == NULL) {
        
		return -1;
    }
    memset(code_units, 0, sizeof(CodeUnits));
    uint8_t bytes = getBytes(code_point);

    if (bytes <= MaxCodeLength) {
        code_units->length = bytes;
        if (bytes > 1) {
            for (bytes = code_units->length - 1; bytes > 0; --bytes) {
                code_units->code[bytes] = (uint8_t)(0x80 | (code_point & 0x3F));
                code_point >>= 6;
                code_units->code[0] |= 0x80;
                code_units->code[0] >>= 1;
            }
            //code_units->code[0] |= 0x80;
            //uint8_t mask = (0xFF ^ code_units->code[0]) >> 1;
            //code_units->code[0] |= mask & code_point;
            code_units->code[0] |= 0x80 | (code_point & ((0xFF ^ code_units->code[0]) >> 1));
        } else {
            code_units->code[0] = (uint8_t)(0x7F & code_point);
        }
        
        return 0;
    } else {
    	
        return 1;
    }
}

uint32_t decode(const CodeUnits *code_unit)
{
    uint32_t out = 0;
    if (code_unit->length > 1) {
        out = code_unit->code[0] & (0xFF >> code_unit->length);
        uint32_t id = 1;
        for (; id < code_unit->length; ++id)
            out <<= 6, out |= code_unit->code[id] & 0x3F;
    } else {
        out = 0x7F & code_unit->code[0];
    }
    
    return out;
}

int write_code_unit(FILE *out, const CodeUnits *code_unit)
{
    if (out == NULL) {
    	
        return 1;
    }
    if (fwrite(code_unit->code, sizeof(uint8_t), code_unit->length, out) == code_unit->length) {
        
		return 0;
    } else {
        
		return -1;
    }
}

int read_next_code_unit(FILE *in, CodeUnits *code_units)
{
    if (in == NULL || feof(in)) {
        
		return 1;
    }
    uint8_t getter = fgetc(in);
    if (getter == EOF) {
        
		return 2;
    }
    memset(code_units, 0, sizeof(CodeUnits));
    if ((getter & 0x80) == 0) {
        code_units->length = 1;
        code_units->code[0] = getter;
    } else {
        uint8_t bytes = 0;
        while (bytes <= MaxCodeLength && (getter & (0x80 >> bytes)) != 0) {
            ++bytes;
        }
        if (bytes == 1 || bytes > MaxCodeLength) {
            
			return read_next_code_unit(in, code_units);
        }
        code_units->length = bytes--;
        code_units->code[0] = getter;
        if (fread(&code_units->code[1], sizeof(uint8_t), bytes, in) != bytes) {
            
			return read_next_code_unit(in, code_units);
        }
    }
    
    return 0;
}
