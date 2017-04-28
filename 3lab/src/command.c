#include "command.h"
#include "coder.h"

int encode_file(const char *in_file_name, const char *out_file_name)
{
    FILE *in = fopen(in_file_name, "r"), *out = fopen(out_file_name, "wb");
    if (in != NULL && out != NULL) {
        uint32_t in_val;
        while (!feof(in) && fscanf(in, "%" SCNx32, &in_val)) {
            CodeUnits unit;
            if (!encode(in_val, &unit)) {
                if (write_code_unit(out, &unit)) {
                    fprintf(stderr, "Error write to bin file '%s' :"
                    " val = %"PRIx32, out_file_name, in_val);
                }
            } else {
                fprintf(stderr, "Error encode value : %"PRIx32,
                in_val);
            }
        }
        fclose(in), fclose(out);
        
		return 0;
    }
    
    return -1;
}

int decode_file(const char *in_file_name, const char *out_file_name)
{
    FILE *in = fopen(in_file_name, "rb"), *out = fopen(out_file_name, "w");
    if (in != NULL && out != NULL) {
        CodeUnits unit;
        while (!feof(in) && read_next_code_unit(in, &unit) == 0) {
            fprintf(out, "%"PRIx32"\n", decode(&unit));
        }
        fclose(in), fclose(out);
        
		return 0;
    }
    
    return -1;
}
