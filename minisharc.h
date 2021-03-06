#ifndef VOLFP_ADDR

#define VOLFP_ADDR	0x2C
#define SHARC_ADDR	0x20
#define POS_VOLUME	2
#define POS_MUTE	3
#define POS_CONFIG	5
#ifndef serprintf
#define serprintf(fmt, ... ) { char ___b[1024]; snprintf(___b, 1023, fmt, ##__VA_ARGS__ ); Serial.println(___b); }
#endif

class MiniSHARC {
public:
	MiniSHARC();
	bool isInitialized();
	void waitForMiniSHARCToInitialize();
	void setConfig(byte config);
	int getConfig();
	int getAttenuation();
	void increaseAttenuation();
	void decreaseAttenuation();
	void increaseAttenuation(int steps);
	void decreaseAttenuation(int steps);
	void setAttenuation(byte targetVolume);
	void resetToDefaults();
	void printStatus();
	void setIsCallbackRegistered(bool value);
	bool isCallbackRegistered();
	void I2CReceiveCallback(int numBytes);
	void check_Sharc();
	void toggleMute();
	bool isMuted();
	void muteOn();
	void muteOff();
	int getVolumePercentage();
	int getAttenuationPercentage();

protected:
	byte _currentAttenuation;
	byte _currentConfig;
	byte _state[6];
	bool _isCallbackRegistered;
	byte _muted;

	void sendI2CBytes(byte major, byte minor);
	void forceMiniSHARCRefresh();
} Sharc;

#endif
