#include <libmx.h>

unsigned long mx_hex_to_nbr(const char *hex) {
    int val = 0;
    int j = 0;
    unsigned long sum = 0;

    if (!hex)
        return 0;
    for (j = 0; hex[j] != '\0'; j++);
    for(int i = 0; hex[i] != '\0'; i++)
    {
        if(hex[i] >= '0' && hex[i] <= '9')
            val = hex[i] - 48;
        else if(hex[i] >= 'a' && hex[i] <= 'f')
            val = hex[i] - 87;
        else if(hex[i] >= 'A' && hex[i] <= 'F')
            val = hex[i] - 55;
        sum += val * mx_pow(16, --j);
    }
    return sum;
}
