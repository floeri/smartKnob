#include "motor_task.h"
#include "display_task.h"
#include "interface.h"
// #include <SimpleFOC.h>
// #include "i2c.h"





TaskHandle_t xTask1;
TaskHandle_t xTask2;
TaskHandle_t xTask3;
//static MotorTask motor_task = MotorTask();
void setup() {
  // monitoring port
  Serial.begin(115200);
  delay(100);
  ffat_init();
  if (!EEPROM.begin(1000)) {
    Serial.println("Failed to initialise EEPROM");
    Serial.println("Restarting...");
    delay(1000);
    ESP.restart();
  }

  pthread_mutex_init(&lvgl_mutex, NULL);
  /* 创建队列，其大小可包含5个元素Data */
  queue_ = xQueueCreate(5, sizeof(Command));
  assert(queue_ != NULL);
  knob_state_queue_ = xQueueCreate(1, sizeof(KnobState));
  assert(knob_state_queue_ != NULL);
  xTaskCreatePinnedToCore(
    interface_run,
    "interface_run",
    8192,
    NULL,
    2,
    &xTask3,
    1);
  xTaskCreatePinnedToCore(
    motor_run,
    "motor_task", /* 任务名称. */
    8192,         /* 任务的堆栈大小 */
    NULL,         /* 任务的参数 */
    1,            /* 任务的优先级 */
    &xTask1,      /* 跟踪创建的任务的任务句柄 */
    1);           /* pin任务到核心0 */

  display_init();
  xTaskCreatePinnedToCore(
    display_run,
    "display_run",
    20000,
    NULL,
    0,
    &xTask2,
    0);


  vTaskDelete(NULL);
}

void loop() {
  // lv_timer_handler(); /* let the GUI do its work */
  // vTaskDelay(0);
  // motor_run();
}
