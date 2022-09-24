#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    LoadStars(v_stars);
    LoadPlanets(v_planets);
    LoadComets(v_comets);
    LoadAstros(v_astros);
    LoadSolarSystems(v_ssystems, v_stars, v_planets);
    idAstro = FindLastId(v_astros);
    idSSystem = FindLastId(v_ssystems);
    v_comboPlanet.push_back(ui->planeta1);
    v_comboStar.push_back(ui->estrela1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_novoAstro_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
    isEditing = false;
    ui->nomeAstro->clear();
    ui->horaDec->clear();
    ui->minDec->clear();
    ui->secDec->clear();
    ui->grauAR->clear();
    ui->minAR->clear();
    ui->secAR->clear();
    ui->distanciaAstro->clear();
    ui->tipoEstrela->clear();
    ui->massaEstelar->clear();
    ui->raioEstelar->clear();
    ui->magApa->clear();
    ui->magAbs->clear();
    ui->tamanhoPlaneta->clear();
    ui->exoPlaneta->setChecked(false);
    ui->nomeSSPLaneta->clear();
    ui->posSSPlaneta->clear();
    ui->materiaisPlaneta->clear();
    ui->excenCometa->clear();
    ui->periodoCometa->clear();
    ui->perielioCometa->clear();
    ui->afelioCometa->clear();
    ui->saveAstro->setText("Salvar");
    ui->tipoAstro->setDisabled(false);
}


void MainWindow::on_listaAstros_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
    ui->tableAstro->clearContents();
    ui->tableStars->clearContents();
    ui->tablePlanets->clearContents();
    ui->tableComets->clearContents();
    ui->tableAstro->setRowCount(0);
    ui->tableStars->setRowCount(0);
    ui->tablePlanets->setRowCount(0);
    ui->tableComets->setRowCount(0);

    for(size_t i = 0; i < v_astros.size(); i++){
        ui->tableAstro->insertRow(i);
        QStringList data;
        data << QString::fromStdString(to_string(v_astros.at(i).GetId()))
             << QString::fromStdString(v_astros.at(i).GetName())
             << (QString::fromStdString(to_string(v_astros.at(i).GetDec().at(0))) + "h " + QString::fromStdString(to_string(v_astros.at(i).GetDec().at(1))) + "m " + QString::fromStdString(to_string(v_astros.at(i).GetDec().at(2))) + "s ")
             << (QString::fromStdString(to_string(v_astros.at(i).GetRA().at(0))) + "° " + QString::fromStdString(to_string(v_astros.at(i).GetRA().at(1))) + "m " + QString::fromStdString(to_string(v_astros.at(i).GetRA().at(2))) + "s ")
             << QString::fromStdString(to_string(v_astros.at(i).GetDistance()));
        for(size_t j = 0; j < 5; j++){
            QTableWidgetItem *item = new QTableWidgetItem((data.at(j)));
            item->setData(0, QVariant(data.at(j)));
            ui->tableAstro->setItem(i,j,item);
        }
    }

    for(size_t i = 0; i < v_stars.size(); i++){
        ui->tableStars->insertRow(i);
        QStringList data;
        data << QString::fromStdString(to_string(v_stars.at(i).GetId()))
             << QString::fromStdString(v_stars.at(i).GetStarType())
             << QString::fromStdString(to_string(v_stars.at(i).GetMass()))
             << QString::fromStdString(to_string(v_stars.at(i).GetRadius()))
             << QString::fromStdString(to_string(v_stars.at(i).GetAppaMag()))
             << QString::fromStdString(to_string(v_stars.at(i).GetAbsMag()));
        for(size_t j = 0; j < 6; j++){
            QTableWidgetItem *item = new QTableWidgetItem((data.at(j)));
            item->setData(0, QVariant(data.at(j)));
            ui->tableStars->setItem(i,j,item);
        }
    }

    for(size_t i = 0; i < v_planets.size(); i++){
        ui->tablePlanets->insertRow(i);
        QStringList data;
        data << QString::fromStdString(to_string(v_planets.at(i).GetId()))
             << QString::fromStdString(to_string(v_planets.at(i).GetSize()))
             << (v_planets.at(i).GetExoplanet()? "Sim" : "Não")
             << QString::fromStdString(v_planets.at(i).GetSSName())
             << QString::fromStdString(to_string(v_planets.at(i).GetPos()))
             << QString::fromStdString(v_planets.at(i).GetMaterials());
        for(size_t j = 0; j < 6; j++){
            QTableWidgetItem *item = new QTableWidgetItem((data.at(j)));
            item->setData(0, QVariant(data.at(j)));
            ui->tablePlanets->setItem(i,j,item);
        }
    }

    for(size_t i = 0; i < v_comets.size(); i++){
        ui->tableComets->insertRow(i);
        QStringList data;
        data << QString::fromStdString(to_string(v_comets.at(i).GetId()))
             << QString::fromStdString(to_string(v_comets.at(i).GetEccentricity()))
             << QString::fromStdString(to_string(v_comets.at(i).GetPeriod()))
             << QString::fromStdString(to_string(v_comets.at(i).GetPerihelion()))
             << QString::fromStdString(to_string(v_comets.at(i).GetAphelion()));
        for(size_t j = 0; j < 5; j++){
            QTableWidgetItem *item = new QTableWidgetItem((data.at(j)));
            item->setData(0, QVariant(data.at(j)));
            ui->tableComets->setItem(i,j,item);
        }
    }

}


void MainWindow::on_novoSistemaSolar_clicked(){
    ui->stackedWidget->setCurrentIndex(2);
    for(int i = 0; i < v_planets.size(); i++){
        ui->planeta1->insertItem(i, QString::fromStdString(to_string(v_planets.at(i).GetId())));
    }
    for(int i = 0; i < v_stars.size(); i++){
        ui->estrela1->insertItem(i, QString::fromStdString(to_string(v_stars.at(i).GetId())));
    }
}


void MainWindow::on_listaSistemaSolares_clicked(){
    ui->stackedWidget->setCurrentIndex(3);
    ui->tableSSystems->clearContents();
    ui->tableSSystems->setRowCount(0);
    for(size_t i = 0; i < v_ssystems.size(); i++){
        ui->tableSSystems->insertRow(i);
        QStringList data;
        data << QString::fromStdString(to_string(v_ssystems.at(i).GetId()));
        data << QString::fromStdString(v_ssystems.at(i).GetName());
        QString planetas;
        for(int j = 0; j < v_ssystems.at(i).GetPlanets().size(); j++){
             planetas += (QString::fromStdString(to_string(v_ssystems.at(i).GetPlanets().at(j)->GetId())) + ",");
        }
        data << planetas;
        QString estrelas;
        for(int j = 0; j < v_ssystems.at(i).GetStars().size(); j++){
             estrelas += (QString::fromStdString(to_string(v_ssystems.at(i).GetStars().at(j)->GetId())) + ",");
        }
        data << estrelas;
        for(size_t j = 0; j < 4; j++){
            QTableWidgetItem *item = new QTableWidgetItem((data.at(j)));
            item->setData(0, QVariant(data.at(j)));
            ui->tableSSystems->setItem(i,j,item);
        }
    }
}

void MainWindow::FillPlanetsComboBox(){
    QComboBox *comboBoxPlanet = new QComboBox(ui->formLayoutWidget_2);
    string nameComboBox = "planeta" + to_string(iPlanets);
    comboBoxPlanet->setObjectName(QString::fromUtf8(nameComboBox));
    v_comboPlanet.push_back(comboBoxPlanet);
    ui->planetsSS->addWidget(comboBoxPlanet);
    for(int i = 0; i < v_planets.size(); i++){
        comboBoxPlanet->insertItem(i, QString::fromStdString(to_string(v_planets.at(i).GetId())));
    }
}

void MainWindow::FillStarsComboBox(){
    QComboBox *comboBoxStar = new QComboBox(ui->formLayoutWidget_2);
    string nameComboBox = "estrela" + to_string(iStars);
    comboBoxStar->setObjectName(QString::fromUtf8(nameComboBox));
    v_comboStar.push_back(comboBoxStar);
    ui->starsSS->addWidget(comboBoxStar);
    for(int i = 0; i < v_stars.size(); i++){
        comboBoxStar->insertItem(i, QString::fromStdString(to_string(v_stars.at(i).GetId())));
    }
}

void MainWindow::on_tipoAstro_currentIndexChanged(int index){
    ui->stackedWidget_2->setCurrentIndex(index);
}


void MainWindow::on_tipoAstroLista_currentIndexChanged(int index){
    ui->stackedWidget_3->setCurrentIndex(index);
}


void MainWindow::on_morePlanet_2_clicked(){
    iPlanets++;
    FillPlanetsComboBox();
}


void MainWindow::on_moreStar_2_clicked(){
    iStars++;
    FillStarsComboBox();
}


void MainWindow::on_removePlanet_2_clicked(){
    iPlanets--;
    if(iPlanets > 1){
        v_comboPlanet.erase(v_comboPlanet.begin() + iPlanets - 1);
        delete ui->planetsSS->itemAt(iPlanets - 1)->widget();

    }
}


void MainWindow::on_removeStar_2_clicked(){
    iStars--;
    if(iStars > 1){
        v_comboStar.erase(v_comboStar.begin()+iStars - 1);
        delete ui->starsSS->itemAt(iStars - 1)->widget();
    }

}


void MainWindow::on_saveAstro_clicked(){
    Astro astro;
    if(isEditing){
        QList<QTableWidgetItem*> itens = ui->tableAstro->selectedItems();
        string s_id = itens.at(0)->text().toStdString();
        size_t id = stol(s_id);
        DeleteAstro(v_astros, id);
        DeleteStar(v_stars, id);
        DeletePlanet(v_planets, id);
        DeleteComet(v_comets, id);
        astro.SetId(id);
    } else {
        idAstro++;
        astro.SetId(idAstro);
    }

    vector<int> v_dec;
    v_dec.push_back(ui->horaDec->value());
    v_dec.push_back(ui->minDec->value());
    v_dec.push_back(ui->secDec->value());
    vector<int> v_ra;
    v_ra.push_back(ui->grauAR->value());
    v_ra.push_back(ui->minAR->value());
    v_ra.push_back(ui->secAR->value());


    astro.SetName(ui->nomeAstro->text().toStdString());
    astro.SetDec(v_dec);
    astro.SetRA(v_ra);
    astro.SetDistance( ui->distanciaAstro->value());
    v_astros.push_back(astro);
    SaveAstro(v_astros);
    if(ui->tipoAstro->currentIndex() == 1){
        Star star;
        star.SetId(idAstro);
        star.SetName(ui->nomeAstro->text().toStdString());
        star.SetDec(v_dec);
        star.SetRA(v_ra);
        star.SetDistance( ui->distanciaAstro->value());
        star.SetStarType(ui->tipoEstrela->text().toStdString());
        star.SetMass(ui->massaEstelar->value());
        star.SetRadius(ui->raioEstelar->value());
        star.SetAppaMag(ui->magApa->value());
        star.SetAbsMag(ui->magAbs->value());
        v_stars.push_back(star);
        SaveStar(v_stars);
        ui->tipoEstrela->clear();
        ui->massaEstelar->clear();
        ui->raioEstelar->clear();
        ui->magApa->clear();
        ui->magAbs->clear();
    } else if(ui->tipoAstro->currentIndex() == 2){
        Planet planet;
        planet.SetId(idAstro);
        planet.SetName(ui->nomeAstro->text().toStdString());
        planet.SetDec(v_dec);
        planet.SetRA(v_ra);
        planet.SetDistance( ui->distanciaAstro->value());
        planet.SetSize(ui->tamanhoPlaneta->value());
        planet.SetExoplanet(ui->exoPlaneta->isChecked());
        planet.SetSSName(ui->nomeSSPLaneta->text().toStdString());
        planet.SetPos(ui->posSSPlaneta->value());
        planet.SetMaterials(ui->materiaisPlaneta->text().toStdString());

        v_planets.push_back(planet);
        SavePlanet(v_planets);
        ui->tamanhoPlaneta->clear();
        ui->exoPlaneta->setChecked(false);
        ui->nomeSSPLaneta->clear();
        ui->posSSPlaneta->clear();
        ui->materiaisPlaneta->clear();
    } else if(ui->tipoAstro->currentIndex() == 3){
        Comet comet;
        comet.SetId(idAstro);
        comet.SetName(ui->nomeAstro->text().toStdString());
        comet.SetEccentricity(ui->excenCometa->value());
        comet.SetPeriod(ui->periodoCometa->value());
        comet.SetPerihelion(ui->perielioCometa->value());
        comet.SetAphelion(ui->afelioCometa->value());

        v_comets.push_back(comet);
        SaveComet(v_comets);
        ui->excenCometa->clear();
        ui->periodoCometa->clear();
        ui->perielioCometa->clear();
        ui->afelioCometa->clear();
    }
    ui->nomeAstro->clear();
    ui->horaDec->clear();
    ui->minDec->clear();
    ui->secDec->clear();
    ui->grauAR->clear();
    ui->minAR->clear();
    ui->secAR->clear();
    ui->distanciaAstro->clear();

    LoadStars(v_stars);
    LoadPlanets(v_planets);
    LoadComets(v_comets);
    LoadAstros(v_astros);

    QMessageBox message(ui->centralwidget);
    message.addButton(QMessageBox::Ok);
    message.setText("Astro salvo com sucesso!");
    message.setFixedSize(300,100);
    message.exec();

    ui->saveAstro->setText("Salvar");
    isEditing = false;
}


void MainWindow::on_deleteAstro_clicked(){
    QList<QTableWidgetItem*> itens = ui->tableAstro->selectedItems();
    string s_id = itens.at(0)->text().toStdString();
    size_t id = stol(s_id);
    DeleteAstro(v_astros, id);
    DeleteStar(v_stars, id);
    DeletePlanet(v_planets, id);
    DeleteComet(v_comets, id);
    SaveAstro(v_astros);
    SaveStar(v_stars);
    SavePlanet(v_planets);
    SaveComet(v_comets);
    LoadStars(v_stars);
    LoadPlanets(v_planets);
    LoadComets(v_comets);
    LoadAstros(v_astros);

    QMessageBox message(ui->centralwidget);
    message.addButton(QMessageBox::Ok);
    message.setText("Astro deletado!");
    message.setFixedSize(325,100);
    message.exec();

    MainWindow::on_listaAstros_clicked();
}


void MainWindow::on_saveSSystem_clicked(){
    idSSystem++;
    SolarSystem ssystem;
    Planet *planet;
    Star *star;
    vector<Planet*> planets;
    vector<Star*> stars;
    ssystem.SetId(idSSystem);
    ssystem.SetName(ui->nomeSSystem->text().toStdString());
    for(int i = 0; i < iPlanets; i++){
        planet = FindPlanet(stoi(v_comboPlanet.at(i)->currentText().toStdString()), v_planets);
        planets.push_back(planet);
    }
    ssystem.SetPlanets(planets);

    for(int i = 0; i < iStars; i++){
        star = FindStar(stoi(v_comboStar.at(i)->currentText().toStdString()), v_stars);
        stars.push_back(star);
    }
    ssystem.SetStars(stars);

    v_ssystems.push_back(ssystem);
    SaveSolarSystem(v_ssystems);
    LoadSolarSystems(v_ssystems, v_stars, v_planets);

    ui->nomeSSystem->clear();

    for(int i = 1; i < iPlanets; i++){
        delete v_comboPlanet.at(i);
    }
    for(int i = 1; i < iStars; i++){
        delete v_comboStar.at(i);
    }
    v_comboStar.clear();
    v_comboPlanet.clear();
    iPlanets = 1;
    iStars = 1;

    QMessageBox message(ui->centralwidget);
    message.addButton(QMessageBox::Ok);
    message.setText("Sistema Solar salvo com sucesso!");
    message.setFixedSize(325,100);
    message.exec();
}


void MainWindow::on_pushButton_clicked(){
    QList<QTableWidgetItem*> itens = ui->tableSSystems->selectedItems();
    string s_id = itens.at(0)->text().toStdString();
    size_t id = stol(s_id);
    DeleteSolarSystem(v_ssystems, id);
    SaveSolarSystem(v_ssystems);
    LoadSolarSystems(v_ssystems, v_stars, v_planets);

    QMessageBox message(ui->centralwidget);
    message.addButton(QMessageBox::Ok);
    message.setText("Sistema Solar deletado!");
    message.setFixedSize(325,100);
    message.exec();

    MainWindow::on_listaSistemaSolares_clicked();
}


void MainWindow::on_editAstro_clicked(){
    QList<QTableWidgetItem*> itens = ui->tableAstro->selectedItems();
    if(itens.size() > 0){
        string s_id = itens.at(0)->text().toStdString();
        size_t id = stol(s_id);
        Astro *astro = FindAstro(id, v_astros);
        Star *star = FindStar(id, v_stars);
        Planet *planet = FindPlanet(id, v_planets);
        Comet *comet = FindComet(id, v_comets);
        if(astro != NULL){
            ui->stackedWidget->setCurrentIndex(0);
            isEditing = true;
            ui->saveAstro->setText("Editar");
            ui->nomeAstro->setText(QString::fromStdString(astro->GetName()));
            ui->horaDec->setValue(astro->GetDec().at(0));
            ui->minDec->setValue(astro->GetDec().at(1));
            ui->secDec->setValue(astro->GetDec().at(2));
            ui->grauAR->setValue(astro->GetRA().at(0));
            ui->minAR->setValue(astro->GetRA().at(1));
            ui->secAR->setValue(astro->GetRA().at(2));
            ui->distanciaAstro->setValue(astro->GetDistance());
        }

        if(star != NULL){
            ui->stackedWidget_2->setCurrentIndex(1);
            ui->tipoAstro->setCurrentIndex(1);
            ui->tipoEstrela->setText(QString::fromStdString(star->GetStarType()));
            ui->massaEstelar->setValue(star->GetMass());
            ui->raioEstelar->setValue(star->GetRadius());
            ui->magApa->setValue(star->GetAppaMag());
            ui->magAbs->setValue(star->GetAbsMag());
        } else if(planet != NULL){
            ui->stackedWidget_2->setCurrentIndex(2);
            ui->tipoAstro->setCurrentIndex(2);
            ui->tamanhoPlaneta->setValue(planet->GetSize());
            ui->exoPlaneta->setChecked(planet->GetExoplanet());
            ui->nomeSSPLaneta->setText(QString::fromStdString(planet->GetSSName()));
            ui->posSSPlaneta->setValue(planet->GetPos());
            ui->materiaisPlaneta->setText(QString::fromStdString(planet->GetMaterials()));
        } else if(comet != NULL){
            ui->stackedWidget_2->setCurrentIndex(3);
            ui->tipoAstro->setCurrentIndex(3);
            ui->excenCometa->setValue(comet->GetEccentricity());
            ui->periodoCometa->setValue(comet->GetPeriod());
            ui->perielioCometa->setValue(comet->GetPerihelion());
            ui->afelioCometa->setValue(comet->GetAphelion());
        }
        ui->tipoAstro->setDisabled(true);
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_actionFoto_triggered()
{
    QMessageBox perfil;
    perfil.setText("José Norberto Fagundes Isaias");
    perfil.setInformativeText("Matrícula: 19202785");
    perfil.setIconPixmap(QPixmap(":/perfil/fotoPerfil.png"));
    perfil.exec();
}

