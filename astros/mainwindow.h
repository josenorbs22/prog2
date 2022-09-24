#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "astro.hpp"
#include "star.hpp"
#include "comet.hpp"
#include "solar-system.hpp"
#include "planet.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_listaAstros_clicked();

    void on_novoAstro_clicked();

    void on_novoSistemaSolar_clicked();

    void on_listaSistemaSolares_clicked();

    void on_tipoAstro_currentIndexChanged(int index);

    void on_tipoAstroLista_currentIndexChanged(int index);

    void on_morePlanet_2_clicked();

    void on_moreStar_2_clicked();

    void on_removePlanet_2_clicked();

    void on_removeStar_2_clicked();

    void on_saveAstro_clicked();

    void on_deleteAstro_clicked();

    void on_saveSSystem_clicked();

    void on_pushButton_clicked();

    void on_editAstro_clicked();

    void on_pushButton_2_clicked();

    void on_actionFoto_triggered();

private:
    Ui::MainWindow *ui;
    int iPlanets = 1;
    int iStars = 1;
    std::vector<QComboBox*> v_comboPlanet;
    std::vector<QComboBox*> v_comboStar;
    vector<Star> v_stars;
    vector<Planet> v_planets;
    vector<Comet> v_comets;
    vector<Astro> v_astros;
    vector<SolarSystem> v_ssystems;
    size_t idAstro, idSSystem;
    bool isEditing;
    void FillPlanetsComboBox();
    void FillStarsComboBox();
};
#endif // MAINWINDOW_H
