#ifndef SENSOROUTPUT_H
#define SENSOROUTPUT_H

#include <QObject>

class Sensor;

/*!
 * SensorOutput
 * A abstract class as a base for all outputs for Sensor data. This
 * class will handle the capture timing and manage the sensor collection,
 * more specialized classes will format the sensor data and write it to
 * the correct output
 */
class SensorOutput : public QObject {
	Q_OBJECT

public:
	enum Type {
		WebSocket,
		CsvFile,
		JsonFile
	};

	explicit SensorOutput(QObject* parent = 0);	//!< Class constructor
	static SensorOutput* createOutput(const QVariantList& configuration);	//!< Factory method

	void addSensor(Sensor* sensor);				//!< Add sensor to output
	void removeSensor(Sensor* sensor);			//!< Remove sensor from output
	int interval() const;						//!< Returns the capture interval in ms
	virtual QString description() const = 0;	//!< Returns a description of output and its settings

signals:
	void intervalChanged(int interval);		//!< Signal that is emitted when the interval changes

public slots:
	void start();						//!< Start generating output
	void start(int interval);			//!< Start generating output at specified interval
	void stop();						//!< Stop generating output
	void setInterval(int interval);		//!< Set capture interval in ms

protected:

	/*!
	 * startCapture
	 * Start capture method to be implemented by specialized classes for initialization. When
	 * this method is called, it's guaranteed that the capture in not running
	 */
	virtual void startCapture() = 0;

	/*!
	 * stopCapture
	 * Stop capture method to be implemented by specialized classes for cleanup. It's guaranteed
	 * that the capture is running when this method is called
	 */
	virtual void stopCapture() = 0;

	/*! handleCapture
	 * Handle captured data to be implemented by specialized classes
	 */
	virtual void handleCapture(const QList<float>&) = 0;

private:
	void timerEvent(QTimerEvent*);		//!< Called at capture interval

	int					_interval;		//!< Capturing interval in ms
	QList<Sensor*>		_sensors;		//!< References to sensors whose readings will be used
	int					_timerId;		//!< Capture interval timer id

};

#endif // SENSOROUTPUT_H
