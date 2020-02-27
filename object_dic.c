#include "object_dic.h"

#include <stdio.h>
#include <stdint.h>


/* 1018 */	typedef struct {
                uint8_t							numberOfEntries;
                uint32_t						vendorID;
                uint32_t						productCode;
                uint32_t						revision;
                uint32_t						serialNumber;
            }OD_identifyObject;


/* 2002 */	typedef struct {
                uint8_t							numberOfEntries;
                uint8_t							syncDriveOperationEnb;
                uint16_t						PDOMinTransIntervalMillisec;
                uint16_t						PDOMaxTransIntervalMillisec;
                int32_t							positionAngleScalingFactor;
                int32_t							speedScalingFactor;
                int16_t							currentScalingFactor;
                uint8_t							WatchdogEnable;
                uint8_t							SystemReset;
            }OD_ComParamEffectingComValues;


/* 2020 */	typedef struct {
                uint16_t						numberOfEntries;
                uint16_t						hakanBirthday;
                uint16_t						goksuBirthday;
                uint16_t						oguzemreBirthday;
                uint16_t						oguzatsizBirthday;
                uint16_t						rehaBirthday;
                uint16_t						sinanBirthday;
            }OD_EmployeeBirthday;

            typedef struct {
/* 1000 */		uint32_t						deviceType;
/* 1001 */		uint8_t							errorRegister;
/* 1006 */		uint32_t						comCyclePeriod;
/* 1007 */		uint32_t						syncWindowsLength;
/* 1008 */		char						    manufacturerDeviceName[11];
/* 1009 */		char							manufacturerHardwareRevision[4];
/* 100A */		char							manufacturerSoftwareRevision[4];
/* 1010 */		uint8_t							storeParameters;
/* 1011 */		uint8_t							restoreParameters;
/* 1017 */		uint16_t						producerHeartbeatTime;
/* 1018 */		OD_identifyObject				identify_object;
/* 2000 */		uint8_t							nodeIdentifier;
/* 2001 */		uint8_t							baudRate;
/* 2002 */		OD_ComParamEffectingComValues	comParamEffectingComValues;
/* 2020 */		OD_EmployeeBirthday				employeeBirthday;
            }ObjectDictionary;

            typedef struct {
                uint16_t						index;
                uint16_t						subindex;
                uint16_t						type;
                uint16_t						length;
                void*							pdata;
            }OD_index_parameters;

            typedef struct {
                void*							pdata;
                uint16_t						type;
                uint16_t						length;
            }OD_subindex_parameters;

            typedef enum {
                READ_ONLY	= (0x0001),
                WRITE_ONLY	= (0x0002),
                READ_WRITE	= (0x0004),
                E
            }OD_type;

            ObjectDictionary	Dictionary = {
/* 1000 */		(0x0000),
/* 1001 */		(0x0000),
/* 1006 */		(0x0000),
/* 1007 */		(0x0000),
/* 1008 */		{0},
/* 1009 */		{0},
/* 100A */		{0},
/* 1010 */		(0x0000),
/* 1011 */		(0x0000),
/* 1017 */		(0x0000),
/* 1018 */		{{0x0000}, {0x0000}, {0x0000}, {0x0000}, {0x0000}},
/* 2000 */		(0x0000),
/* 2001 */		(0x0000),
/* 2002 */		{{0x0000}, {0x0000}, {0x0000}, {0x0000}, {0x0000}},
/* 2020 */		{{0x0000}, {0x0000}, {0x0000}, {0x0000}, {0x0000}}
            };

            const OD_index_parameters	ObjectDictionaryParameters[15] = {
                { (0x1000) , (0x0000) , (READ_ONLY) ,	(4) ,	(void*)&Dictionary.deviceType },
                { (0x1001) , (0x0000) , (READ_ONLY) ,	(1) ,	(void*)&Dictionary.errorRegister },
                { (0x1006) , (0x0000) , (READ_WRITE) ,	(4) ,	(void*)&Dictionary.comCyclePeriod },
                { (0x1007) , (0x0000) , (READ_WRITE) ,	(4) ,	(void*)&Dictionary.syncWindowsLength },
                { (0x1008) , (0x0000) , (CONST_) ,		(11) ,	(void*)&Dictionary.manufacturerDeviceName },
                { (0x1009) , (0x0000) , (CONST_) ,		(4) ,	(void*)&Dictionary.manufacturerHardwareRevision },
                { (0x100A) , (0x0000) , (CONST_) ,		(4) ,	(void*)&Dictionary.manufacturerSoftwareRevision },
                { (0x1010) , (0x0000) , (READ_WRITE) ,	(1) ,	(void*)&Dictionary.storeParameters },
                { (0x1011) , (0x0000) , (FREE) ,		(1) ,	(void*)&Dictionary.restoreParameters },
                { (0x1017) , (0x0000) , (READ_WRITE) ,	(2) ,	(void*)&Dictionary.producerHeartbeatTime },
                { (0x1018) , (0x0004) , (READ_ONLY) ,	(0) ,	(void*)&Dictionary.identify_object },
                { (0x2000) , (0x0000) , (READ_WRITE) ,	(1) ,	(void*)&Dictionary.nodeIdentifier },
                { (0x2001) , (0x0000) , (READ_WRITE) ,	(1) ,	(void*)&Dictionary.baudRate },
                { (0x2002) , (0x0008) , (FREE) ,		(0) ,	(void*)&Dictionary.comParamEffectingComValues },
                { (0x2020) , (0x0006) , (FREE) ,		(0) ,	(void*)&Dictionary.employeeBirthday },
            };

            const OD_subindex_parameters	IdentifyObject[5] = {
                {(void*)&Dictionary.identify_object.numberOfEntries,	READ_ONLY, 1 },
                {(void*)&Dictionary.identify_object.vendorID,			READ_ONLY, 4 },
                {(void*)&Dictionary.identify_object.productCode,		READ_ONLY, 4 },
                {(void*)&Dictionary.identify_object.revision,			READ_ONLY, 4 },
                {(void*)&Dictionary.identify_object.serialNumber,		READ_ONLY, 4 }
            };

            const OD_subindex_parameters	ComParamEffectingComValues[9] = {
                {(void*)&Dictionary.comParamEffectingComValues.numberOfEntries,				READ_WRITE, 1 },
                {(void*)&Dictionary.comParamEffectingComValues.syncDriveOperationEnb,		READ_WRITE, 2 },
                {(void*)&Dictionary.comParamEffectingComValues.PDOMinTransIntervalMillisec, READ_WRITE, 2 },
                {(void*)&Dictionary.comParamEffectingComValues.PDOMaxTransIntervalMillisec, READ_WRITE, 2 },
                {(void*)&Dictionary.comParamEffectingComValues.positionAngleScalingFactor,	READ_WRITE, 4 },
                {(void*)&Dictionary.comParamEffectingComValues.speedScalingFactor,			READ_WRITE, 4 },
                {(void*)&Dictionary.comParamEffectingComValues.currentScalingFactor,		READ_WRITE, 2 },
                {(void*)&Dictionary.comParamEffectingComValues.WatchdogEnable,				READ_WRITE, 1 },
                {(void*)&Dictionary.comParamEffectingComValues.SystemReset,					WRITE_ONLY, 1 }
            };

            const OD_subindex_parameters	EmployeeBirthday[7] = {
                {(void*)&Dictionary.employeeBirthday.numberOfEntries,	READ_ONLY, 2 },
                {(void*)&Dictionary.employeeBirthday.hakanBirthday,		READ_ONLY, 2 },
                {(void*)&Dictionary.employeeBirthday.goksuBirthday,		READ_ONLY, 2 },
                {(void*)&Dictionary.employeeBirthday.oguzemreBirthday,	READ_ONLY, 2 },
                {(void*)&Dictionary.employeeBirthday.oguzatsizBirthday, READ_ONLY, 2 },
                {(void*)&Dictionary.employeeBirthday.rehaBirthday,		READ_ONLY, 2 },
                {(void*)&Dictionary.employeeBirthday.sinanBirthday,		READ_ONLY, 2 }
            };




