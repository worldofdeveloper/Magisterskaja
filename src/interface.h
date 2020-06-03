int mqtt_int; // интервал отправки данных по MQTT в секундах 
bool stat_led;
bool toBool(String);

void parameters(){
// создаем параметры для нашего проекта
  jee.var("wifi", "STA"); // режим работы WiFi по умолчанию ("STA" или "AP")  (параметр в энергонезависимой памяти)
  jee.var("ssid", "Etereshop_office"); // имя точки доступа к которой подключаемся (параметр в энергонезависимой памяти)
  jee.var("pass", "0164f008"); // пароль точки доступа к которой подключаемся (параметр в энергонезависимой памяти)

  jee.var("led", "0");  
 }

void update(){ // функция выполняется после ввода данных в веб интерфейсе. получение параметров из веб интерфейса в переменные
  // получаем данные в переменную в ОЗУ для дальнейшей работы
  stat_led = toBool(jee.param("led")); // читаем параметр в переменную с переобразованием в нужный тип данных
}

void interface(){ // функция в которой мы формируем веб интерфейс и интерфейс в приложении JeeUI2

  jee.app("Первая программа"); // название программы (отображается в веб интерфейсе)

  // создаем меню
  jee.menu("Светодиод");
  jee.menu("Настройки MQTT");
  jee.menu("Настройки Wi-Fi");
     jee.page(); // разделитель между страницами
     jee.checkbox("led", "Диод");
      jee.page();
  // Страница "Настройки MQTT"
  jee.formMqtt(); // готовая форма настроек MQTT

  jee.page(); // разделитель между страницами
  // Страница "Настройки WiFi"
  jee.formWifi(); // готовая форма настроек Wi-Fi
  jee.page(); // разделитель между страницами

}