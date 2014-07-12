#include <unistd.h>
#include "gpio-operation.h"

using namespace std;

int main()   {                
	int r = gpio_export(21);
	gpio_set_dir(21, true);
	int i = 0;
	int value = 0;
	while (true)
	{
		gpio_set_value(21, value);
		usleep(1000000);
		value = 1 - value;
		i++;
		if (i == 10)
		{
			break;
		}
	}
	return 0;
}
