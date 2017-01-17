/*
 * hackAIR Arduino Library
 * Copyright © 2016-2017 hackAir Consortium
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file Header file for the hackAIR library
 * @author Thanasis Georgiou
 */

#ifndef hackAIR_h
#define hackAIR_h

// Sensors
#define SENSOR_DFROBOT 1
#define SENSOR_PMS5003 1 // Rebrand of DFRobot sensor (or DFRobot is a rebrand of this one?)
#define SENSOR_SDS011 2
#define SENSOR_GP2Y1010AU0F 3
#define SENSOR_DN7C3CA006 4
#define SENSOR_GROVE 5

// Shield pins
#define PIN_SERIAL_TX 7
#define PIN_SERIAL_RX 8
#define PIN_IO_1 A0
#define PIN_IO_2 A1

#include "Arduino.h"
#include <SoftwareSerial.h>

class hackAIR {
public:
	// Constructors
	hackAIR(int sensor);

	/**
	 * Initialize the sensor (pin modes, buses, etc)
	 */
	void begin();
    
    /**
     * Read data from the sensor and process packages. Mainly used for digital/serial
     * sensors.
     */
    int refresh();

    /**
     * Get the value of 2.5um particles
     */
	float readPM25();
    
    /**
     * Get the value of 10um particles
     */
    float readPM10();
    
     /**
     * Get the value of 0.1um particles
     */
    float readPM01();
    
    /**
     * Get the raw reading value. For sensors that don't exactly measure particulate matter.
     */
    int readRaw();

private:
    int _sensorType;
    float _pm25;
    float _pm10;
    float _pm01;
    long _lastTime;
    long _pulseDuration;
    unsigned char _buff[32];
};

#endif
