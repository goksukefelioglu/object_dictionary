#include "object_dic.h"
// To force compiler to use 1 byte packaging

ObjectDictionary Dictionary = {
    /* 1000 */ (0x0000),
    /* 1001 */ (0x0000),
    /* 1006 */ (0x0000),
    /* 1007 */ (0x0000),
    /* 1008 */ {0},
    /* 1009 */ {0},
    /* 100A */ {0},
    /* 1010 */ (0x0000),
    /* 1011 */ (0x0000),
    /* 1017 */ (0x0000),
    /* 1018 */ {0x04, 0x0000, 0x0000, 0x0000, 0x0000},
    /* 2000 */ (0x0000),
    /* 2002 */
    {0x08, 0x0000, 0x0000, 0x0000, 0x000, 0x0000, 0x0000, 0x0000, 0x0000}};

ObjectDictionaryEEPROM EEPROMDictionary = {

    /* 2001 */ (0x0000),
    /* 2020 */ {0x06, 1993, 1993, 1993, 1993, 1993, 1993}};

const OD_subindex_parameters IdentifyObject[5] = {
    {(void *)&Dictionary.identify_object.numberOfEntries, READ_ONLY, 1},
    {(void *)&Dictionary.identify_object.vendorID, READ_ONLY, 4},
    {(void *)&Dictionary.identify_object.productCode, READ_ONLY, 4},
    {(void *)&Dictionary.identify_object.revision, READ_ONLY, 4},
    {(void *)&Dictionary.identify_object.serialNumber, READ_ONLY, 4}};

const OD_subindex_parameters ComParamEffectingComValues[9] = {
    {(void *)&Dictionary.comParamEffectingComValues.numberOfEntries, READ_WRITE,
     1},
    {(void *)&Dictionary.comParamEffectingComValues.syncDriveOperationEnb,
     READ_WRITE, 2},
    {(void *)&Dictionary.comParamEffectingComValues.PDOMinTransIntervalMillisec,
     READ_WRITE, 2},
    {(void *)&Dictionary.comParamEffectingComValues.PDOMaxTransIntervalMillisec,
     READ_WRITE, 2},
    {(void *)&Dictionary.comParamEffectingComValues.positionAngleScalingFactor,
     READ_WRITE, 4},
    {(void *)&Dictionary.comParamEffectingComValues.speedScalingFactor,
     READ_WRITE, 4},
    {(void *)&Dictionary.comParamEffectingComValues.currentScalingFactor,
     READ_WRITE, 2},
    {(void *)&Dictionary.comParamEffectingComValues.WatchdogEnable, READ_WRITE,
     1},
    {(void *)&Dictionary.comParamEffectingComValues.SystemReset, WRITE_ONLY,
     1}};

const OD_subindex_parameters EmployeeBirthday[7] = {
    {(void *)&EEPROMDictionary.employeeBirthday.numberOfEntries, READ_ONLY, 1},
    {(void *)&EEPROMDictionary.employeeBirthday.hakanBirthday,
     READ_ONLY + EEPROM_DATA, 2},
    {(void *)&EEPROMDictionary.employeeBirthday.goksuBirthday,
     READ_ONLY + EEPROM_DATA, 2},
    {(void *)&EEPROMDictionary.employeeBirthday.oguzemreBirthday,
     READ_ONLY + EEPROM_DATA, 2},
    {(void *)&EEPROMDictionary.employeeBirthday.oguzatsizBirthday,
     READ_ONLY + EEPROM_DATA, 2},
    {(void *)&EEPROMDictionary.employeeBirthday.rehaBirthday,
     READ_ONLY + EEPROM_DATA, 2},
    {(void *)&EEPROMDictionary.employeeBirthday.sinanBirthday,
     READ_ONLY + EEPROM_DATA, 2}};

const OD_index_parameters ObjectDictionaryParameters[15] = {
    {(0x1000), (0x0000), (READ_ONLY), (4), (void *)&Dictionary.deviceType},
    {(0x1001), (0x0000), (READ_ONLY), (1), (void *)&Dictionary.errorRegister},
    {(0x1006), (0x0000), (READ_WRITE), (4), (void *)&Dictionary.comCyclePeriod},
    {(0x1007), (0x0000), (READ_WRITE), (4),
     (void *)&Dictionary.syncWindowsLength},
    {(0x1008), (0x0000), (READ_ONLY), (11),
     (void *)&Dictionary.manufacturerDeviceName},
    {(0x1009), (0x0000), (READ_ONLY), (4),
     (void *)&Dictionary.manufacturerHardwareRevision},
    {(0x100A), (0x0000), (READ_ONLY), (4),
     (void *)&Dictionary.manufacturerSoftwareRevision},
    {(0x1010), (0x0000), (READ_WRITE), (1),
     (void *)&Dictionary.storeParameters},
    {(0x1011), (0x0000), (READ_WRITE), (1),
     (void *)&Dictionary.restoreParameters},
    {(0x1017), (0x0000), (READ_WRITE), (2),
     (void *)&Dictionary.producerHeartbeatTime},
    {(0x1018), (0x0004), (0), (0), (void *)&Dictionary.identify_object},
    {(0x2000), (0x0000), (READ_WRITE), (1), (void *)&Dictionary.nodeIdentifier},
    {(0x2001), (0x0000), (READ_WRITE + EEPROM_DATA), (1),
     (void *)&EEPROMDictionary.baudRate},
    {(0x2002), (0x0008), (0), (0),
     (void *)&Dictionary.comParamEffectingComValues},
    {(0x2020), (0x0006), (0), (0), (void *)&EEPROMDictionary.employeeBirthday},
};
