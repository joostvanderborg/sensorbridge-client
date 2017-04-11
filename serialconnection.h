#ifndef SERIALCONNECTION_H
#define SERIALCONNECTION_H

#include <QObject>

class QSerialPort;
class QByteArray;
class QDataStream;
class Sensor;

class SerialConnection : public QObject {
	Q_OBJECT

public:
	explicit SerialConnection(QObject *parent = 0);

	static int getSensorCount();						//!< Get the sensor count
	QList<Sensor*> getSensors();						//!< Get a list of sensors

public slots:
	void openConnection(const QString &portName);		//!< Open the serial connection and read the serial data
	void closeConnection();								//!< Close the serial connection

private slots:
	void readData();									//!< Parse available data on the serial port

private:
	Sensor*					sensors[SERIAL_ANALOG_SENSORS];		//!< The sensors
	QSerialPort*			port;								//!< The serial port that the sensors communicate over
	QByteArray*				buffer;								//!< Serial buffer

};

#endif // SERIALCONNECTION_H
