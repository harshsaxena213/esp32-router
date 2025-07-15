#include <stdio.h>
#include <esp_wifi.h>
#include <esp_log.h>

void static wifi_event(void *args, esp_event_base_t event_base, int32_t event_id, void *event_data)
{
    static char *tag = "ESP_ROUTER";
    if (event_base == WIFI_EVENT)
    {
        switch (event_id)
        {
        case WIFI_EVENT_STA_START:
            ESP_LOGI(TAG, "STA STARTED ...");
            break;

        case WIFI_EVENT_STA_CONNECTED:
            ESP_LOGI(TAG, "STA CONNECTED...");
            break;

        case WIFI_EVENT_STA_DISCONNECTED:
            ESP_LOGI(TAG, "STA DISSCONNECTED..");
            break;
        case WIFI_EVENT_AP_START:
            ESP_LOGI(TAG, "AP STARTED...");
            break;
        case WIFI_EVENT_AP_STACONNECTED:
            ESP_LOGI(TAG, "A Device Connected..");
            break;
        case WIFI_EVENT_AP_STADISCONNECTED:
            ESP_LOGI(TAG, "A Device Disconnected..");
            break;
        default:
            ESP_LOGI(TAG, "Unkown Event Happend\n %d", event_id);
            break;
        }
    }
    else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP)
    {
        ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;
        ESP_LOGI(TAG, "A DEVICE GOT A IP : " IPSTR, IP2STR(&event->ip_info.ip));
    }
}


void app_main(void){

}