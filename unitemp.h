#ifndef UNITEMP
#define UNITEMP

/* Подключение стандартных библиотек */

/* Подключение API Flipper Zero */
#include "furi.h"
//Файловый поток
#include <toolbox/stream/file_stream.h>
//Уведомления
#include <notification/notification.h>
#include <notification/notification_messages.h>

/* Объявление макроподстановок */
//Имя приложения
#define APP_NAME "Unitemp"
//Путь хранения файлов плагина
#define APP_PATH_FOLDER "/ext/unitemp"
//Имя файла с настройками
#define APP_FILENAME_SETTINGS "settings.cfg"
//Имя файла с датчиками
#define APP_FILENAME_SENSORS "sensors.cfg"

/* Объявление перечислений */
//Единицы измерения
typedef enum { CELSIUM, FARENGATE } units;

/* Объявление структур */
//Настройки плагина
typedef struct {
    //Бесконечная работа подсветки
    bool infinityBacklight;
    //Единица измерения температуры
    //Ложь - градусы Цельсия, истина - Фарeнгейты
    units unit;
} UnitempSettings;

//Основная структура плагина
typedef struct {
    //Основные настройки
    UnitempSettings settings;

    //SD-карта
    Storage* storage; //Хранилище
    Stream* file_stream; //Файловый поток

    //Уведомления
    NotificationApp* notifications;
} Unitemp;

/* Объявление прототипов функций */

#endif