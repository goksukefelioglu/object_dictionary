#ifndef OBJECT_DIC_H
#define OBJECT_DIC_H

#include <stdint.h>
#include <stdio.h>

/* 1018 */ typedef struct {
  uint8_t numberOfEntries;
  uint32_t vendorID;
  uint32_t productCode;
  uint32_t revision;
  uint32_t serialNumber;
} OD_identifyObject;

/* 2002 */ typedef struct {
  uint8_t numberOfEntries;
  uint8_t syncDriveOperationEnb;
  uint16_t PDOMinTransIntervalMillisec;
  uint16_t PDOMaxTransIntervalMillisec;
  int32_t positionAngleScalingFactor;
  int32_t speedScalingFactor;
  int16_t currentScalingFactor;
  uint8_t WatchdogEnable;
  uint8_t SystemReset;
} OD_ComParamEffectingComValues;

/* 2020 */ typedef struct {
  uint8_t numberOfEntries;
  uint16_t hakanBirthday;
  uint16_t goksuBirthday;
  uint16_t oguzemreBirthday;
  uint16_t oguzatsizBirthday;
  uint16_t rehaBirthday;
  uint16_t sinanBirthday;
} OD_EmployeeBirthday;

typedef struct {
  /* 1000 */ uint32_t deviceType;
  /* 1001 */ uint8_t errorRegister;
  /* 1006 */ uint32_t comCyclePeriod;
  /* 1007 */ uint32_t syncWindowsLength;
  /* 1008 */ char manufacturerDeviceName[11];
  /* 1009 */ char manufacturerHardwareRevision[4];
  /* 100A */ char manufacturerSoftwareRevision[4];
  /* 1010 */ uint8_t storeParameters;
  /* 1011 */ uint8_t restoreParameters;
  /* 1017 */ uint16_t producerHeartbeatTime;
  /* 1018 */ OD_identifyObject identify_object;
  /* 2000 */ uint8_t nodeIdentifier;
  /* 2002 */ OD_ComParamEffectingComValues comParamEffectingComValues;
} ObjectDictionary;

typedef struct {
  /* 2001 */ uint8_t baudRate;
  /* 2020 */ OD_EmployeeBirthday employeeBirthday;
} ObjectDictionaryEEPROM;

typedef struct {
  uint16_t index;
  uint16_t subindex;
  uint16_t type;
  uint16_t length;
  void *pdata;
} OD_index_parameters;

typedef struct {
  void *pdata;
  uint16_t type;
  uint16_t length;
} OD_subindex_parameters;

typedef enum {
  READ_ONLY = (0x0001),
  WRITE_ONLY = (0x0002),
  READ_WRITE = (0x0004),
  EEPROM_DATA = (0x0008)
} OD_type;

extern ObjectDictionaryEEPROM EEPROMDictionary;
extern ObjectDictionary Dictionary;

#endif // OBJECT_DIC_H
