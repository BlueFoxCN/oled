#define OLED_DC 24
#define OLED_RESET 20


#include <unistd.h>
#include "gpio-operation.h"
#include "SSD1306.h"

using namespace std;

SSD1306 oled(OLED_DC, OLED_RESET);

void gpio_blink(int gpio, int interval, int repeat_time);

int main()   {                
//	gpio_blink(21, 100, 20);
	oled.ssd1306_init(SSD1306_SWITCHCAPVCC);
	oled.display(); // show splashscreen
	usleep(2000000);
	oled.clear();
	oled.fillrect(0, 0, SSD1306_LCDWIDTH-1, SSD1306_LCDHEIGHT-1, WHITE);
	oled.display();
	usleep(2000000);
	oled.setpixel(10, 10, WHITE);
	oled.display();
	usleep(2000000);
	oled.clear();
}

void gpio_blink(int gpio, int interval, int repeat_time)
{
	int r = gpio_export(gpio);
	gpio_set_dir(gpio, true);
	int i = 0;
	int value = 0;
	while (true)
	{
		gpio_set_value(gpio, value);
		usleep(interval * 1000);
		value = 1 - value;
		i++;
		if (i == repeat_time)
		{
			break;
		}
	}
}
