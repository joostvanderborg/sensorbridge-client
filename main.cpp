#include <QApplication>

#include "core/bridgeengine.h"
#include "ui/mainwindow.h"
#include <QThread>

int main(int argc, char *argv[]) {

	// Setup application
	QApplication app(argc, argv);
	app.setApplicationName("SensorBridge");
	app.setApplicationDisplayName("Sensor Bridge");
	app.setOrganizationName("CLEVER°FRANKE");
	app.setOrganizationDomain("com.cleverfranke");
	app.setApplicationVersion("0.1.0");

	// Construct engine (initialization is done by mainwindow)
	BridgeEngine engine;

	// Construct and show mainwindow
	MainWindow mainWindow(&engine);
//	mainWindow.show();

	return app.exec();

}
