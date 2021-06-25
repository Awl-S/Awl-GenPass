# Awl GenPass
# Разработана для проекта Softers & Neyton-Devs 
## Когда-то для защиты пароля было достаточно иметь злую бабушку на входе в машинный зал

### Менеджер паролей с сохранением данных | Password manager with data saving.
Надежный пароль – это главный барьер, который мешает взломать большинство ваших аккаунтов в сети. Если вы не пользуетесь современными методиками создания паролей, то вполне возможно, что мошенники смогут подобрать их буквально за несколько часов. Чтобы не подвергать себя риску кражи идентификационных данных и не стать жертвой вымогательства, вам нужно создавать пароли, которые могут противостоять усилиям хакеров, вооруженных современными средствами взлома. 

### Проверьте пароль который вы используете:
* Ваш пароль длинный? Постарайтесь создать пароль длиной как минимум 10–12 символов, а лучше даже еще длиннее.
* Ваш пароль трудно угадать? Избегайте простых последовательностей («12345», «qwerty») – такие пароли подбираются за считаные секунды. По той же причине избегайте распространенных слов («password1»).
* Разнообразен ли состав символов в вашем пароле? Заглавные и строчные буквы, символы, цифры – всем им найдется достойное место в вашем пароле. Чем больше в пароле разнотипных символов, тем он менее предсказуем.
* Есть ли в вашем паролеочевидные подстановки символов? Например, ноль вместо буквы «О». Современные хакерские программы учитывают подобные замены, так что старайтесь их избегать.
* Есть ли в вашем пароле необычные сочетания слов? Кодовые фразы надежнее, если слова в них идут в неожиданном порядке. Даже если вы используете обычные слова, берите такие, которые не связаны друг с другом по смыслу, и расставляйте их нелогичным образом. Это поможет противостоять словарному подбору.
* Пользовались ли вы этим паролем раньше? Повторное использование паролей может скомпрометировать сразу несколько аккаунтов. Каждый пароль должен быть уникальным.
Используете ли вы правило, которое трудно разгадать компьютеру? Например, пароль из трех 4-буквенных слов, в которых первые две буквы заменяются цифрами и символами. Выглядит это так: «?4ей#2ка?6цо» вместо «улейрукалицо».

# У данной программы есть две версии:
## AWL-S GenPass Standart: 
* Сбор данных: адрес сайта, ваш логин и размер пароля для генерации.
* Пароль аннализируется и указывается примерная оценка пароля.
* Данные записываются в файл AWL-S Password.txt
## AWL-S GenPass Telegram: 
* Особенность: Настройка личного телеграмм бота для сохранения паролей в Telegram Chat.

# Менеджер паролей (64x-32x)
* AWL-S GenPass Standart [vk.cc/c31Ff6](https://vk.cc/c31Ff6) 
* AWL-S GenPass Telegram [vk.cc/c325kv6](https://vk.cc/c325kv) 

#Установка Telegram версии:
Для установки telegram версии вам необходимо установить Python и две библиотеки.
* [Python](https://www.python.org/)
После установки открываем консоль и используем команды установки библиотек:
* pip install asyncio
* pip install aiogram
### Token
Далее нам нужно создать бота в Telegram.
Пишем в чат @BotFather
* /newbot
* Имя нашего бота [StreamStats]
* @ Для нашего бота [StreamStats_bot]
Название может быть любое, главное чтоб оно было не занято.
* Копируем токен и открываем в файл telegram.py через блокнот или другой любой редактор.
* Находим строчку [bot = Bot(token="Ваш Токен")] - и вместо "Ваш Токен" вставляем уже ваш токен, "" - обязательны.
### ChatID
* @get_id_bot - пишем боту и копируем наш chatID
* * Находим строчку [chatID = "Ваш ChatID"] - и вместо "Ваш chatID" вставляем уже ваш ID, "" - обязательны.
### Сохраняем файл и выходим. Бот готов к использованию.
# Внимание!!!
Бот не собирает ваши данные и не использует их. Все файлы сохраняются у вас на устройстве и доступ к ним имеете только Вы.
Меняйте пароль раз в 90 дней, для полной безопастности и исключения утечки вашего пароля из базы данных.
Рекомендации для пароля более >12 символов. 
###### Awl studio
