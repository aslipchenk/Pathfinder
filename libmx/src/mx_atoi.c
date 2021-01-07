#include "libmx.h"

int mx_atoi(const char *str) {
	unsigned long long res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && mx_isspace(*str))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && mx_isdigit(*str)) {
		res = res * 10 + (*str - 48);
		if (negative > 0 && res > 2147483647)
            return -1;
        if (negative < 0 && res > 2147483648)
            return 0;
		++str;
	}
	return (res * negative);
}
