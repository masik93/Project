#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "User.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    this    ->loadTableMain();
    
    ui->cboxClient->clear();
     ui->cboxClient->addItem("Выберите клиента");
     //ui->cboxClient->addItem(m_user->getName());

    foreach (Client item, Client::getClientList())
    {
        ui->cboxClient->addItem(item.getName());
    }



    QSqlQueryModel      *modelStatistics = new QSqlQueryModel();
    modelStatistics->setQuery("select name as 'Наименование\nпрепарата', number as 'Количество\nна складе', price as 'Цена', info as 'Информация о\nпрепарате' from preparation;");
    ui->tableViewPreparationInfo->setModel(modelStatistics);

}


MainWindow::~MainWindow()
{
    delete ui;
    
    if(m_lstPreparation != nullptr)
    {
        delete m_lstPreparation;
    }
}

void MainWindow::show(User *user)
{
    QMainWindow::show();
    
    m_user = user;
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    switch(index)
    {
    case 0: 
    {
        loadTableMain();
    } break;
    case 1:
    {
        loadTablePreparation();
    } break;
    case 2: 
    {
        loadTableClients();
    } break;
    case 3: 
    {
        loadTableProviders();
    } break;
    }
}

/// ******************** Вкладка "Клиенты"

void MainWindow::on_tableViewClients_clicked(const QModelIndex &index)
{
    // Определяем ID выбранной записи
    QModelIndex     selectedUser = ui->tableViewClients->model()->index(index.row(), 0, QModelIndex());
    strSelectedUserID = selectedUser.data(0).toString();
    
    QString strSelectedUserFIO;
    // Определяем ID выбранной записи
    QModelIndex     selectedUserFIO = ui->tableViewClients->model()->index(index.row(), 1, QModelIndex());
    strSelectedUserFIO = selectedUserFIO.data(0).toString();
    ui->leSelectedClient->setText(strSelectedUserFIO);
}

void MainWindow::on_pbAddUser_clicked()
{
    AddUser     *addUser = new AddUser();
    addUser     ->show();
    
    connect(addUser, SIGNAL(userAdded()), this, SLOT(loadTableClients())); 
}

void MainWindow::on_pbDeleteUser_clicked()
{
    QSqlQuery       queryDelUser;
    QString         strDelUser = "";
    
    for(int x{0}; x<3; ++x)
    {
        switch(x)
        {
        case 0: strDelUser = "DELETE FROM clients WHERE id_user = " + strSelectedUserID + ";"; break;
        case 1: strDelUser = "DELETE FROM employee WHERE id_user = " + strSelectedUserID + ";"; break;
        case 2: strDelUser = "DELETE FROM User WHERE id = " + strSelectedUserID + ";"; break;
        }
        
        if(queryDelUser.exec(strDelUser))
        {
            if(x == 2)
            {
                QMessageBox::information(nullptr, "Information ", "Пользователь удален!");
            }
        }
    }
    
    this->loadTableClients();
    
    ui->leSelectedClient->clear();
}

void MainWindow::loadTableClients()
{    
    QString         strGetLoadTable = "select "
                                      "us.id, us.surname as 'Фамилия', "
                                      "us.name as 'Имя', "
                                      "us.patronymic as 'Отчество', "
                                      "us.login as 'Логин', "
                                      "us.password as 'Пароль', "
                                      "(SELECT phone FROM clients where id_user = us.id) as 'Телефон', "
                                      "(SELECT post FROM employee where id_user = us.id) as 'Должность' "
                                      "from "
                                      "User us ";
    
    modelClientsLoad.setQuery(strGetLoadTable, QSqlDatabase::database());
    
    ui->tableViewClients->setModel(&modelClientsLoad);
    // Включаем сортировку в представлении 
    ui->tableViewClients->setSortingEnabled(true);
    // Построчное выделение
    ui->tableViewClients->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Выделение не более одной строки за раз
    ui->tableViewClients->setSelectionMode(QAbstractItemView::SingleSelection);
    // Отключаем редактирование таблицы
    ui->tableViewClients->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewClients->setColumnWidth(1, 170);
    ui->tableViewClients->setColumnWidth(2, 170);
    ui->tableViewClients->setColumnWidth(3, 170);
    ui->tableViewClients->setColumnWidth(4, 100);
    ui->tableViewClients->setColumnWidth(5, 110);
    ui->tableViewClients->setColumnWidth(6, 115);
    ui->tableViewClients->setColumnWidth(7, 130);
    ui->tableViewClients->setColumnHidden(0, true);
    ui->tableViewClients->show();
}

void MainWindow::on_tableViewClients_doubleClicked(const QModelIndex &index)
{
    QString objectSelectedClient;
    // Определяем номер выбранной записи
    QModelIndex     clientNumber = ui->tableViewClients->model()->index(index.row(), 0, QModelIndex());
    objectSelectedClient = clientNumber.data(0).toString();
    
    AddUser   *updateUser = new AddUser(objectSelectedClient);
    updateUser       ->setAttribute(Qt::WA_DeleteOnClose);
    updateUser       ->show();
    
    connect(updateUser, SIGNAL(userAdded()), this, SLOT(loadTableClients()));
}

/// ******************** Вкладка "Поставщики"

void MainWindow::on_tableViewProviders_clicked(const QModelIndex &index)
{
    // Определяем ID выбранной записи
    QModelIndex     selectedProvider = ui->tableViewProviders->model()->index(index.row(), 0, QModelIndex());
    strSelectedProviderID = selectedProvider.data(0).toString();
    
    QString strSelectedProviderName;
    // Определяем ID выбранной записи
    QModelIndex     selectedProviderName = ui->tableViewProviders->model()->index(index.row(), 1, QModelIndex());
    strSelectedProviderName = selectedProviderName.data(0).toString();
    ui->leSelectedProvider->setText(strSelectedProviderName);
}

void MainWindow::on_tableViewProviders_doubleClicked(const QModelIndex &index)
{
    QString objectSelectedProvider;
    // Определяем номер выбранной записи
    QModelIndex     providerNumber = ui->tableViewProviders->model()->index(index.row(), 0, QModelIndex());
    objectSelectedProvider = providerNumber.data(0).toString();
    
    AddProvider     *addProvider = new AddProvider(objectSelectedProvider);
    addProvider     ->show();
    
    connect(addProvider, SIGNAL(providerAdded()), this, SLOT(loadTableProviders())); 
}

void MainWindow::on_pbAddProvider_clicked()
{
    AddProvider     *addProvider = new AddProvider();
    addProvider     ->show();
    
    connect(addProvider, SIGNAL(providerAdded()), this, SLOT(loadTableProviders())); 
}

void MainWindow::on_pbDeleteProvider_clicked()
{
    QSqlQuery       queryDelProvider;
    QString         strDelProvider = "DELETE FROM provider WHERE id = " + strSelectedProviderID + ";";
    
    if(queryDelProvider.exec(strDelProvider))
    {
        QMessageBox::information(nullptr, "Information ", "Поставщик удален!");
    }
    
    this->loadTableProviders();
    
    ui->leSelectedProvider->clear();
}

void MainWindow::loadTableProviders()
{
    QString         strGetLoadTableProviders = "SELECT id, name as 'Наименование поставщика', address as 'Адрес', phone as 'Телефон', UNN as 'УНН' FROM provider ";
    
    modelProvidersLoad.setQuery(strGetLoadTableProviders, QSqlDatabase::database());
    
    ui->tableViewProviders->setModel(&modelProvidersLoad);
    // Включаем сортировку в представлении 
    ui->tableViewProviders->setSortingEnabled(true);
    // Построчное выделение
    ui->tableViewProviders->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Выделение не более одной строки за раз
    ui->tableViewProviders->setSelectionMode(QAbstractItemView::SingleSelection);
    // Отключаем редактирование таблицы
    ui->tableViewProviders->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewProviders->setColumnWidth(1, 250);
    ui->tableViewProviders->setColumnWidth(2, 250);
    ui->tableViewProviders->setColumnWidth(3, 250);
    ui->tableViewProviders->setColumnWidth(4, 210);
    ui->tableViewProviders->setColumnHidden(0, true);
    ui->tableViewClients->show();
}

/// ******************** Вкладка "Препараты"

// Определяем ID выбранной записи
void MainWindow::on_tableViewPreparationInfo_clicked(const QModelIndex &index)
{
    QModelIndex     selectedPreparation = ui->tableViewPreparationInfo->model()->index(index.row(), 0, QModelIndex());
    strSelectedPreparationID = selectedPreparation.data(0).toString();
}

void MainWindow::on_tableViewPreparationInfo_doubleClicked(const QModelIndex &index)
{
    QString objectSelectedPreparation;
    // Определяем номер выбранной записи
    QModelIndex     preparationNumber = ui->tableViewPreparationInfo->model()->index(index.row(), 0, QModelIndex());
    objectSelectedPreparation = preparationNumber.data(0).toString();
    
    AddPreparation  *preparation = new AddPreparation(objectSelectedPreparation);
    preparation     ->setAttribute(Qt::WA_DeleteOnClose);
    preparation     ->show();
    
    connect(preparation, SIGNAL(preparationAdded()), this, SLOT(loadTablePreparation()));
}

void MainWindow::on_pbAddPreparation_clicked()
{
    AddPreparation  *preparation = new AddPreparation();
    preparation     ->setAttribute(Qt::WA_DeleteOnClose);
    preparation     ->show();
    
    connect(preparation, SIGNAL(preparationAdded()), this, SLOT(loadTablePreparation()));
}

void MainWindow::on_pbDeletePreparation_clicked()
{
    QSqlQuery       queryDelPreparation;
    QString         strDelPreparation = "DELETE FROM preparation WHERE id = " + strSelectedPreparationID + ";";
    
    if(queryDelPreparation.exec(strDelPreparation))
    {
        QMessageBox::information(nullptr, "Information ", "Препарат удален!");
    }
    
    this->loadTablePreparation();
}

void MainWindow::loadTablePreparation()
{
    QString         strGetLoadTable = "select id, name as 'Наименование\nпрепарата', number as 'Количество\nна складе', price as 'Цена,р.', info as 'Информация о\nпрепарате' from preparation ";
    
    modelPrepapration.setQuery(strGetLoadTable, QSqlDatabase::database());
    
    ui->tableViewPreparationInfo->setModel(&modelPrepapration);
    // Включаем сортировку в представлении 
    ui->tableViewPreparationInfo->setSortingEnabled(true);
    // Построчное выделение
    ui->tableViewPreparationInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Выделение не более одной строки за раз
    ui->tableViewPreparationInfo->setSelectionMode(QAbstractItemView::SingleSelection);
    // Отключаем редактирование таблицы
    ui->tableViewPreparationInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewPreparationInfo->setColumnWidth(1, 120);
    ui->tableViewPreparationInfo->setColumnWidth(2, 120);
    ui->tableViewPreparationInfo->setColumnWidth(3, 70);
    ui->tableViewPreparationInfo->setColumnWidth(4, 800);
    ui->tableViewPreparationInfo->setColumnHidden(0, true);
    ui->tableViewPreparationInfo->show();
}

/// ******************** Вкладка "Главная"


void MainWindow::on_pbAddToOrder_clicked()
{
    AddOrder    *order = new AddOrder();
    order       ->setAttribute(Qt::WA_DeleteOnClose);
    order       ->show();
    
    connect(order, SIGNAL(preparationAdded(Preparation)), this, SLOT(addToOrderList(Preparation)));
}

void MainWindow::addToOrderList(Preparation pr)
{
    m_lstPreparation->append(pr);
    
    calculateSum(m_lstPreparation);
    
    this    -> loadTableMain();
}

void MainWindow::loadTableMain()
{
    if(m_lstPreparation == nullptr)
    {
        m_lstPreparation = new QList<Preparation>;
    }
    
    ui->cboxClient->clear();
    ui->cboxClient->addItem("Выберите клиента");
    foreach (Client item, Client::getClientList())
    {
        ui->cboxClient->addItem(item.getLogin());
    }
    
    m_modelMain = new QStandardItemModel(m_lstPreparation->size(),4);
    
    m_modelMain->setHeaderData(0,Qt::Horizontal,"Название\nпрепарата");
    m_modelMain->setHeaderData(1,Qt::Horizontal,"Количество");
    m_modelMain->setHeaderData(2,Qt::Horizontal,"Цена за ед.");
    m_modelMain->setHeaderData(3,Qt::Horizontal,"Описание");
    
    for (int row = 0; row < m_lstPreparation->size(); ++row)
    {
        QStandardItem *item1 = new QStandardItem((m_lstPreparation->at(row).getName()));
        m_modelMain->setItem(row, 0, item1);
        QStandardItem *item2 = new QStandardItem((m_lstPreparation->at(row).getNumber()));
        m_modelMain->setItem(row, 1, item2);
        QStandardItem *item3 = new QStandardItem((m_lstPreparation->at(row).getPrice()));
        m_modelMain->setItem(row, 2, item3);
        QStandardItem *item4 = new QStandardItem((m_lstPreparation->at(row).getInfo()));
        m_modelMain->setItem(row, 3, item4);
    }
    
    ui->tableViewMain->setModel(m_modelMain);
    
    ui->tableViewMain->setColumnWidth(0, 100);
    ui->tableViewMain->setColumnWidth(1, 100);
    ui->tableViewMain->setColumnWidth(2, 100);
    ui->tableViewMain->setColumnWidth(3, 670);
}

void MainWindow::on_tableViewMain_clicked(const QModelIndex &index)
{
    strSelectedPreparationRow = ui->tableViewMain->model()->index(index.row(), 0, QModelIndex()).row();
}

//reset
void MainWindow::on_reset_button_clicked()
{
    //получаем наш исполняемый файл для перезагрузки и соответственно перезагружаем
  QCoreApplication* Ax = QApplication::instance();
Ax->quit();
QProcess::startDetached(Ax->arguments()[0], Ax->arguments());

}
// Сохранене информации о покупке в БД
void MainWindow::on_pbToPay_clicked()
{
    // Сохранение чека в БД
    QSqlQuery       querySaveCheckToDB;
    QString         strSaveCheckToDB = "INSERT INTO "
                                       "checks(id_client, id_employee, date) "
                                       "VALUES "
                                       "((SELECT c.id FROM User u, clients c where u.login = '" + ui->cboxClient->currentText() + "' and u.id = c.id_user), (SELECT e.id FROM User u, employee e where u.login = '" + m_user->getLogin() + "' and u.id = e.id_user), CURRENT_TIMESTAMP);";
    
    querySaveCheckToDB.exec(strSaveCheckToDB);
    
    
    // Получение id текущего чека
    QSqlQuery       queryGetLastCheckId;
    QString         strGetLastCheckId = "SELECT last_insert_rowid() as id;";

    if(!queryGetLastCheckId.exec(strGetLastCheckId))
    {
        QMessageBox::warning(nullptr, "Error ", "Ошибка получения id чека!");
    }
    
    QSqlRecord      recordGetLastCheckId = queryGetLastCheckId.record();      
    
    while (queryGetLastCheckId.next())
    {
        strLastCheckId = queryGetLastCheckId.value(recordGetLastCheckId.indexOf("id")).toString();
    }
    
    // Сохранение информации о сделанном заказе
    
    QSqlQuery       querySaveOrderToDB;
    QString         strSaveOrderToDB = "INSERT INTO "
                                       "orders(id_preparations, id_check, number) "
                                       "VALUES ";
    for (int item{}; item<m_lstPreparation->size(); ++item)
    {
        if(item == m_lstPreparation->size()-1)
        {
            strSaveOrderToDB.append("(" + Preparation::getId_preparation(m_lstPreparation->at(item).getName()) + ", " + strLastCheckId + ", " + m_lstPreparation->at(item).getNumber() + ")");            
        }
        else
        {
            strSaveOrderToDB.append("(" + Preparation::getId_preparation(m_lstPreparation->at(item).getName()) + ", " + strLastCheckId + ", " + m_lstPreparation->at(item).getNumber() + "),");
        }
    }
    strSaveOrderToDB.append(";");
    
    if(querySaveOrderToDB.exec(strSaveOrderToDB))
    {
        cWin = new CheckWindow(m_summ, strLastCheckId, m_lstPreparation);
        cWin            ->show();
    }
    
    for (int item{}; item<m_lstPreparation->size(); ++item)
    {
        QSqlQuery       queryUpdateDB;
        QString         strUpdateDB = "UPDATE "
                                      "preparation "
                                      "SET "
                                      "number = (SELECT number FROM preparation where name = '" + m_lstPreparation->at(item).getName() + "')- " + m_lstPreparation->at(item).getNumber() + " "
                                      "WHERE "
                                      "name = '" + m_lstPreparation->at(item).getName() + "';";
        
        queryUpdateDB.exec(strUpdateDB);
    }
    
    m_lstPreparation->clear();
    ui->lcdNumber->display(0);
    
    loadTableMain();
}

void MainWindow::on_pbRemoveFromOrder_clicked()
{
    m_lstPreparation->removeAt(strSelectedPreparationRow);
    
    calculateSum(m_lstPreparation);
    
    this    ->loadTableMain();
}

void MainWindow::on_cboxClient_currentIndexChanged(int index)
{
    if(index != 0)
    {
        ui->pbToPay->setEnabled(true);
    }
    else
    {
        ui->pbToPay->setDisabled(true);
    }
}

void MainWindow::calculateSum(QList<Preparation> *lstPrep)
{
    // Вычисление суммы покупки
    m_summ = 0;
    
    for(int item{}; item<lstPrep->size(); ++item)
    {
        m_summ += lstPrep->at(item).getNumber().toInt() * lstPrep->at(item).getPrice().toDouble();
    }
    // Вывод суммы покупки на дисплей
    ui->lcdNumber->display(m_summ);
}
