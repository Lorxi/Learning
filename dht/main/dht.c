#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <dht.h>
#include <esp_log.h>
#include <driver/gpio.h>

static const char *TAG = "main";

dht_sensor_type_t my_dht = DHT_TYPE_AM2301;

const gpio_num_t DHT_PIN = 25;

void app_main(void)
{
    float temperature, humidity;

    while (1)
    {
        dht_read_float_data(my_dht, DHT_PIN, &humidity, &temperature);
        ESP_LOGI(TAG, "Humidity: %.1f%% Temp: %.1fC\n", humidity, temperature);

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
