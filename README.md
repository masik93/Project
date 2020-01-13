# **Разработка и документирование бизнес требований**

## Требования к проекту

### Содержание
[1 Введение](#1-%D0%B2%D0%B2%D0%B5%D0%B4%D0%B5%D0%BD%D0%B8%D0%B5)

[2 Требования пользователя](#2-%D1%82%D1%80%D0%B5%D0%B1%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F-%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8F)

[2.1 Программные интерфейсы](#21-%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%BD%D1%8B%D0%B5-%D0%B8%D0%BD%D1%82%D0%B5%D1%80%D1%84%D0%B5%D0%B9%D1%81%D1%8B)

[2.2 Интерфейс пользователя](#22-%D0%B8%D0%BD%D1%82%D0%B5%D1%80%D1%84%D0%B5%D0%B9%D1%81-%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8F)

[2.3 Характеристики пользователей](#23-%D1%85%D0%B0%D1%80%D0%B0%D0%BA%D1%82%D0%B5%D1%80%D0%B8%D1%81%D1%82%D0%B8%D0%BA%D0%B8-%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8F)

[3 Системные требования](#3-%D1%81%D0%B8%D1%81%D1%82%D0%B5%D0%BC%D0%BD%D1%8B%D0%B5-%D1%82%D1%80%D0%B5%D0%B1%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F)

[3.1 Функциональные требования](#31--%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D0%BE%D0%BD%D0%B0%D0%BB%D1%8C%D0%BD%D1%8B%D0%B5-%D1%82%D1%80%D0%B5%D0%B1%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F)

[3.2 Нефункциональные требования](#32-%D0%BD%D0%B5%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D0%BE%D0%BD%D0%B0%D0%BB%D1%8C%D0%BD%D1%8B%D0%B5-%D1%82%D1%80%D0%B5%D0%B1%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F)

[3.2.1 Атрибуты качества](#321-%D0%B0%D1%82%D1%80%D0%B8%D0%B1%D1%83%D1%82%D1%8B-%D0%BA%D0%B0%D1%87%D0%B5%D1%81%D1%82%D0%B2%D0%B0)

[3.2.2 Требования к безопасности](#322-%D1%82%D1%80%D0%B5%D0%B1%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F-%D0%BA-%D0%B1%D0%B5%D0%B7%D0%BE%D0%BF%D0%B0%D1%81%D0%BD%D0%BE%D1%81%D1%82%D0%B8)

[4. UML Диаграммы](https://github.com/masik93/Project/tree/master/images) <bvr>

### 1 Введение

  Тип приложения: Программа для реализации товаров с базой данных.
Название продукта: Аптека.

Предназначена для ведения торгово-складского учёта на предприятиях. Торговые программы используют для автоматизации основных процессов торговой деятельности; осуществления реализации товара; контроля количества проданной и имеющейся в наличии продукции. Внедрение программы позволит ускорить время работы с клиентами. Встроенная база данных позволяет иметь представление о количестве товаров которые есть в наличии.

### 2 Требования пользователя

#### 2.1 Программные интерфейсы
  
  1. Графический интерфейс пользователя должен обеспечиваться встроенными в Windows системными библиотеками Windows API, для хранения данных используется база данных MySQL.
  
 #### 2.2 Интерфейс пользователя
 
 - Окно авторизации
 
 ![Image alt](https://github.com/masik93/Project/blob/master/images/0.png?raw=true "Optional Title")
 
 Рисунок 1. Окно аторизации
 
 Содержит поля для ввода Логина и Пароля пользователя, кнопку подтверждения (Ок) и кнопку отмены (Отмена).
 
 - Окно реализации товаров
 
 ![Image alt](https://github.com/masik93/Project/blob/master/images/1.png?raw=true "Optional Title")
 
 Рисунок 2. Главное окно программы 
 
 Главное окно содержит кнопки Добавить к заказу, Удалить из заказа, Перезагрузка и Оплатить. Также расположен информационный список, в котором отображаются товары добавленные в чек для реализации. В списке присутствует возможность сортировки товаров по одному из полей. В правом нижнем углу присутствует индикатор показывающий общую сумму покупок добавленных к продаже. В зависимости от необходимой функции выполенния программы пользователь нажимает на одну из данных кнопнок. Затем следует инструкция, всплываемая на экране (диалоговые окна).
 
 - Окно сформированного чека
 
 ![Image alt](https://github.com/masik93/Project/blob/master/images/2.png?raw=true "Optional Title")
 
 Рисунок 3. Окно сформированного чека
 
 Содержит список проданных товаров с указанием полной информации о них и итоговую сумму по чеку.
 
 - Окно просмотра детальной информации о товаре
 
 ![Image alt](https://github.com/masik93/Project/blob/master/images/3.png?raw=true "Optional Title")
 
 Рисунок 4. Окно просмотра детальной информации о товаре
 
 Содержит кнопки Добавить препарат, Удалить препарат. Препараты распаложены в виде списка. В списке присутствует возможность сортировки товаров по одному из полей. В зависимости от необходимой функции выполенния программы пользователь нажимает на одну из данных кнопнок. Затем следует инструкция, всплываемая на экране (диалоговые окна). Также заложена функция контроля количества товаров имеющихся в наличии: красным цветом отображаются позиции которых 5 и меньше, желтым - от 6 до 10. Двойной щелчок по любой записи позволяет редактировать ее.
 
 - Окно просмотра детальной информации о пользователях программы
 
 ![Image alt](https://github.com/masik93/Project/blob/master/images/4.png?raw=true "Optional Title")
 
 Рисунок 5. Окно просмотра детальной информации о пользователях программы
 
Содержит кнопки Добавить клиента, Удалить клиента. Клиенты распаложены в виде списка. В списке присутствует возможность сортировки строк по одному из полей. В зависимости от необходимой функции выполенния программы пользователь нажимает на одну из данных кнопнок. Затем следует инструкция, всплываемая на экране (диалоговые окна). Двойной щелчок по любой записи позволяет редактировать ее.
 
  - Окно просмотра детальной информации о поставщиках
 
 ![Image alt](https://github.com/masik93/Project/blob/master/images/5.png?raw=true "Optional Title")
 
 Рисунок 6. Окно просмотра детальной информации о поставщиках
 
Содержит кнопки Добавить поставщика, Удалить поставщика. Поставщики распаложены в виде списка. В списке присутствует возможность сортировки строк по одному из полей. В зависимости от необходимой функции выполенния программы пользователь нажимает на одну из данных кнопнок. Затем следует инструкция, всплываемая на экране (диалоговые окна). Двойной щелчок по любой записи позволяет редактировать ее.
 
 Также есть кнопки Свернуть, Развернуть и Выход - стандарные кнопки. 
 
 Главным моментом данной программы является реализация товаров. 
 Чтобы происходило более удобное функционирование процесаа, вкладки программы выполнены в одном стиле для простоты и быстроты ознакомления пользователя.
  
 #### 2.3 Характеристики пользователя
 
 Пользователями являются работники торговой отрасли, так как данная программа предназначена для торговых заведений.
 
 ### 3 Системные требования
 
 Информационная автоматизированная система может работать под управлением операционной системы Windows от компании Microsoft.
 

#### 3.1  Функциональные требования

1. Реализация лекарственных средств;

2. Добавление и удаление поставщиков лекарственных средств;

3. Добавление и удаление лекарственных средств с возможность внесения дополнительной информации о них;

4. Добавление и удаление пользователей программы;

5. Осуществление контроля количества товара находящегося на складе. Производится выделение товара если его количество ниже необходимого минимума;

6. Сортировка баз данных от А до Я и наоборот;

7. Возможность смены пользователя.

#### 3.2 Нефункциональные требования

##### 3.2.1 Атрибуты качества

Как правило, говоря о нефункциональных требованиях, чаще всего говорят об атрибутах качества (т.е. требованиях, определяющих качественные характеристики разрабатываемого программного обеспечения или системы, такие как производительность, надежность, масштабируемость), не обращая внимания на другие виды нефункциональных требований, а именно:

 Атрибуты качества:
 
 Атрибуты, важные для разработчиков:
 1. Ограничения - Разработка должна вестись на платформе для ПК;
 2. Бизнес-правила - Простота интерфейса для оптимизации и ускорения работы.
 
 Атрибуты, важные для пользователей:
 1. Внешние интерфейсы - Удобство в использовании;
 
 2. Лёгкость в эксплуатации - Во время загрузки и в процесее работы, программа должна быть интуитивно понятна, и требовать минимальное количество действий;
 
 3. Скорость процесса - Особенно важный пункт для работы с большими данными;
 
 4. Стабильная работа приложения;
 
 5. Надежность.
 
 ##### 3.2.2 Требования к безопасности
 
Требования к безопасности, как правило, включают в себя три большие категории: требования, связанные с разграничением доступа, требования, связанные с работой с приватными данным, и требования, направленные на снижение рисков от внешних атак.
Надежное функционирование автоматизированной системы должно быть обеспечено выполнением организационно-технических мероприятий, таких как:

1.скорость ввыполнения процессов;

2.использование лицензионного программного обеспечения;

3.организация бесперебойного питания путем использования блоков бесперебойного питания.
