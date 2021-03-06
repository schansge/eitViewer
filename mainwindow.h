#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <functional>
#include <mpflow/mpflow.h>
#include "image.h"
#include "measurementsystem.h"
#include "solver.h"
#include "calibrator.h"
#include "datalogger.h"
#include "mirrorserver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void analyse();
    void on_actionOpen_triggered();
    void on_actionExit_triggered();
    void on_actionLoad_Measurement_triggered();
    void on_actionSave_Measurement_triggered();
    void on_actionCalibrate_triggered();
    void on_actionAuto_Calibrate_toggled(bool arg1);
    void on_actionCalibrator_Settings_triggered();
    void on_actionSave_Image_triggered();
    void on_actionRun_DataLogger_toggled(bool arg1);
    void on_actionSave_DataLogger_triggered();
    void on_actionVersion_triggered();
    void solver_initialized(bool success);
    void calibrator_initialized(bool success);
    void update_solver_menu_items(bool success);
    void update_calibrator_menu_items(bool success);
    void close_solver();

protected:
    void initTable();
    bool hasMultiGPU() { int devCount = 0; cudaGetDeviceCount(&devCount); return devCount > 1; }
    void addAnalysis(QString name, QString unit, std::function<mpFlow::dtype::real(
        const Eigen::Ref<Eigen::ArrayXf>&)> analysis);

public:
    // accessor
    MeasurementSystem* measurement_system() { return this->measurement_system_; }
    Solver* solver() { return this->solver_; }
    Calibrator* calibrator() { return this->calibrator_; }
    DataLogger* datalogger() { return this->datalogger_; }
    MirrorServer* mirrorserver() { return this->_mirrorserver; }
    std::vector<std::tuple<int, QString,
        std::function<mpFlow::dtype::real(const Eigen::Ref<Eigen::ArrayXf>&)>>>&
        analysisFunctions() { return this->analysisFunctions_; }
    std::vector<std::tuple<QString, QString>>& analysis() { return this->analysis_; }
    QString& open_file_name() { return this->open_file_name_; }

private:
    Ui::MainWindow *ui;
    MeasurementSystem* measurement_system_;
    Solver* solver_;
    Calibrator* calibrator_;
    DataLogger* datalogger_;
    MirrorServer* _mirrorserver;
    std::vector<std::tuple<int, QString,
        std::function<mpFlow::dtype::real(const Eigen::Ref<Eigen::ArrayXf>&)>>>
        analysisFunctions_;
    std::vector<std::tuple<QString, QString>> analysis_;
    QTimer* analysis_timer_;
    QString open_file_name_;
};

#endif // MAINWINDOW_H
