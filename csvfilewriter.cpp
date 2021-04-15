#include "csvfilewriter.h"
#include <QHash>

/*
 * CSVFileWriter::CSVFileWriter
 */
CSVFileWriter::CSVFileWriter(QObject *parent) : QObject(parent)
{
    m_enabledReadSpiID	= false;
    m_enabledSpiRW		= false;
    m_enabledReadQSpiID	= false;
    m_enabledQSpiRW		= false;
    m_enabledDisplay	= false;
    m_enabledBacklight	= false;
    m_enabledBuzzEst	= false;
    m_enabledBuzzInt	= false;
    m_enabledEncoder	= false;
    m_enabledDipSwitch	= false;
    m_enabledCpu		= false;
    m_enabledFlash		= false;
    m_enabledSD			= false;
    m_enabledETH		= false;
    m_enabledWifi		= false;
    m_enabledModBus		= false;
    m_enabledModBus2	= false;
    m_enabledCanBus		= false;
    m_enabledEcsBus		= false;
    m_enabledNtc		= false;
    m_enabledAnalog		= false;
    m_enabledRtcVbat    = false;
    m_enabledI2CEE		= false;
    m_enabledEthNtp		= false;
    m_enabledEthMac		= false;
    m_enabledCloud		= false;
    m_enabledUsb		= false;
    m_enabledFinalize	= false;

    for(uint8_t i=0; i<COLLAUDO_END_TESTS; i++)
    {
        m_test[i].test_name = "";
        m_test[i].test_en_var = NULL;
        m_test[i].test_params = NULL;
    }

    m_test[COLLAUDO_START].test_en_var = &m_enabledStart;
    m_test[COLLAUDO_FLASH_SPI_RID].test_en_var = &m_enabledReadSpiID;
    m_test[COLLAUDO_FLASH_SPI_RW].test_en_var = &m_enabledSpiRW;
    m_test[COLLAUDO_FLASH_QSPI_RID].test_en_var = &m_enabledReadQSpiID;
    m_test[COLLAUDO_FLASH_QSPI_RW].test_en_var = &m_enabledQSpiRW;
    m_test[COLLAUDO_DISPLAY_TOUCH].test_en_var = &m_enabledDisplay;
    m_test[COLLAUDO_BACKLIGHT].test_en_var = &m_enabledBacklight;
    m_test[COLLAUDO_BUZZER_ESTERNO].test_en_var = &m_enabledBuzzEst;
    m_test[COLLAUDO_BUZZER_INTERNO].test_en_var = &m_enabledBuzzInt;
    m_test[COLLAUDO_ENCODER].test_en_var = &m_enabledEncoder;
    m_test[COLLAUDO_DIP_SWITCH].test_en_var = &m_enabledDipSwitch;
    m_test[COLLAUDO_CPU].test_en_var = &m_enabledCpu;
    m_test[COLLAUDO_FLASH].test_en_var = &m_enabledFlash;
    m_test[COLLAUDO_SD].test_en_var = &m_enabledSD;
    m_test[COLLAUDO_ETHERNET].test_en_var = &m_enabledETH;
    m_test[COLLAUDO_WIFI].test_en_var = &m_enabledWifi;
    m_test[COLLAUDO_MODBUS].test_en_var = &m_enabledModBus;
    m_test[COLLAUDO_MODBUS2].test_en_var = &m_enabledModBus2;
    m_test[COLLAUDO_CAN].test_en_var = &m_enabledCanBus;
    m_test[COLLAUDO_ECSBUS].test_en_var = &m_enabledEcsBus;
    m_test[COLLAUDO_NTC].test_en_var = &m_enabledNtc;
    m_test[COLLAUDO_ANALOGICHE].test_en_var = &m_enabledAnalog;
    m_test[COLLAUDO_RTC_VBAT].test_en_var = &m_enabledRtcVbat;
    m_test[COLLAUDO_I2C_EEPROM].test_en_var = &m_enabledI2CEE;
    m_test[COLLAUDO_SET_DATE_FROM_NTP_ETH].test_en_var = &m_enabledEthNtp;
    m_test[COLLAUDO_WRITE_MAC].test_en_var = &m_enabledEthMac;
    m_test[COLLAUDO_WRITE_CLOUD].test_en_var = &m_enabledCloud;
    m_test[COLLAUDO_USB].test_en_var = &m_enabledUsb;
    m_test[COLLAUDO_FINALIZE].test_en_var = &m_enabledFinalize;

    m_test[COLLAUDO_START].test_name = "COLLAUDO_START";
    m_test[COLLAUDO_FLASH_SPI_RID].test_name = "COLLAUDO_FLASH_SPI_RID";
    m_test[COLLAUDO_FLASH_SPI_RW].test_name = "COLLAUDO_FLASH_SPI_RW";
    m_test[COLLAUDO_FLASH_QSPI_RID].test_name = "COLLAUDO_FLASH_QSPI_RID";
    m_test[COLLAUDO_FLASH_QSPI_RW].test_name = "COLLAUDO_FLASH_QSPI_RW";
    m_test[COLLAUDO_DISPLAY_TOUCH].test_name = "COLLAUDO_DISPLAY_TOUCH";
    m_test[COLLAUDO_BACKLIGHT].test_name = "COLLAUDO_BACKLIGHT";
    m_test[COLLAUDO_BUZZER_ESTERNO].test_name = "COLLAUDO_BUZZER_ESTERNO";
    m_test[COLLAUDO_BUZZER_INTERNO].test_name = "COLLAUDO_BUZZER_INTERNO";
    m_test[COLLAUDO_ENCODER].test_name = "COLLAUDO_ENCODER";
    m_test[COLLAUDO_DIP_SWITCH].test_name = "COLLAUDO_DIP_SWITCH";
    m_test[COLLAUDO_CPU].test_name = "COLLAUDO_CPU";
    m_test[COLLAUDO_FLASH].test_name = "COLLAUDO_FLASH";
    m_test[COLLAUDO_SD].test_name = "COLLAUDO_SD";
    m_test[COLLAUDO_ETHERNET].test_name = "COLLAUDO_ETHERNET";
    m_test[COLLAUDO_WIFI].test_name = "COLLAUDO_WIFI";
    m_test[COLLAUDO_MODBUS].test_name = "COLLAUDO_MODBUS";
    m_test[COLLAUDO_MODBUS2].test_name = "COLLAUDO_MODBUS2";
    m_test[COLLAUDO_CAN].test_name = "COLLAUDO_CAN";
    m_test[COLLAUDO_ECSBUS].test_name = "COLLAUDO_ECSBUS";
    m_test[COLLAUDO_NTC].test_name = "COLLAUDO_NTC";
    m_test[COLLAUDO_ANALOGICHE].test_name = "COLLAUDO_ANALOGICHE";
    m_test[COLLAUDO_RTC_VBAT].test_name = "COLLAUDO_RTC_VBAT";
    m_test[COLLAUDO_I2C_EEPROM].test_name = "COLLAUDO_I2C_EEPROM";
    m_test[COLLAUDO_SET_DATE_FROM_NTP_ETH].test_name = "COLLAUDO_SET_DATE_FROM_NTP_ETH";
    m_test[COLLAUDO_WRITE_MAC].test_name = "COLLAUDO_WRITE_MAC";
    m_test[COLLAUDO_WRITE_CLOUD].test_name = "COLLAUDO_WRITE_CLOUD";
    m_test[COLLAUDO_USB].test_name = "COLLAUDO_USB";
    m_test[COLLAUDO_FLASH_QSPI_PRG].test_name = "COLLAUDO_FLASH_QSPI_PRG";
    m_test[COLLAUDO_FLASH_QSPI_DEL].test_name = "COLLAUDO_FLASH_QSPI_DEL";
    m_test[COLLAUDO_FLASH_SPI_WBIN].test_name = "COLLAUDO_FLASH_SPI_WBIN";
    m_test[COLLAUDO_FLASH_SPI_DEL].test_name = "COLLAUDO_FLASH_SPI_DEL";
    m_test[COLLAUDO_FINALIZE].test_name = "COLLAUDO_FINALIZE";
}


/******************************************************************************
 **** CSVFileWriter::getStartData
 */
void CSVFileWriter::generateFile(const QString &outpath)
{
    QString params;
    qDebug() << "GENERATE FILE" << QSysInfo::machineHostName();

    QFile file("out.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << "# File generated with Alpha5 tool\n";
    out << "# On PC " << QSysInfo::machineHostName() << " \n";

    for(uint8_t i=0; i<COLLAUDO_END_TESTS; i++)
    {
        if(m_test[i].test_en_var)
        {
            if( *(m_test[i].test_en_var) == true )
            {
                out << m_test[i].test_name;
                params = parseTestParams(i);
                if( params.length() )
                    out << ", ";
                out << params;
                out << "\n";

            }
        }
    }
    file.close();
}

void CSVFileWriter::openFile(const QString &fileName)
{
    QString testParams = "";

    if (fileName == "")
        return;

    const QUrl u = QUrl(fileName);
    if (u.isValid())
        qDebug() << "***: " << u.toLocalFile();
    else
        return;

    QFile file(u.toLocalFile());

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    for(uint8_t i=0; i<COLLAUDO_END_TESTS; i++)
        if(m_test[i].test_en_var)
            *(m_test[i].test_en_var) = false;

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString testName;
        QString line = in.readLine();
        if(line[0] == '#')
            continue;

        qDebug() << "line " << line;
        QStringList fields = line.split(",");
        testName = fields.takeFirst().trimmed();

        for(uint8_t i=0; i<COLLAUDO_END_TESTS; i++)
        {
            if(m_test[i].test_name == testName)
            {
                if(m_test[i].test_en_var)
                    *(m_test[i].test_en_var) = true;

                if(m_test[i].test_params) {
                    delete m_test[i].test_params;
                    m_test[i].test_params = nullptr;
                }
                if(fields.size()) {
                    m_test[i].test_params = new QStringList();
                    while(fields.size())
                        m_test[i].test_params->append( fields.takeFirst().trimmed() );
                }
            }
        }
    }

    file.close();
    /* TODO: put this in struct */
    emit enabledReadSpiIDChanged(m_enabledReadSpiID);
    emit enabledSpiRWChanged(m_enabledSpiRW);
    emit enabledReadQSpiIDChanged(m_enabledReadQSpiID);
    emit enabledQSpiRWChanged(m_enabledQSpiRW);
    emit enabledDisplayChanged(m_enabledDisplay);
    emit enabledBacklightChanged(m_enabledBacklight);
    emit enabledBuzzEstChanged(m_enabledBuzzEst);
    emit enabledBuzzIntChanged(m_enabledBuzzInt);
    emit enabledEncoderChanged(m_enabledEncoder);
    emit enabledDipSwitchChanged(m_enabledDipSwitch);
    emit enabledCpuChanged(m_enabledCpu);
    emit enabledFlashChanged(m_enabledFlash);
    emit enabledSDChanged(m_enabledSD);
    emit enabledETHChanged(m_enabledETH);
    emit enabledWifiChanged(m_enabledWifi);
    emit enabledModBusChanged(m_enabledModBus);
    emit enabledModBus2Changed(m_enabledModBus2);
    emit enabledCanBusChanged(m_enabledCanBus);
    emit enabledEcsBusChanged(m_enabledEcsBus);
    emit enabledNtcChanged(m_enabledNtc);
    emit enabledAnalogChanged(m_enabledAnalog);
    emit enabledRtcVbatChanged(m_enabledRtcVbat);
    emit enabledI2CEEChanged(m_enabledI2CEE);
    emit enabledEthNtpChanged(m_enabledEthNtp);
    emit enabledEthMacChanged(m_enabledEthMac);
    emit enabledCloudChanged(m_enabledCloud);
    emit enabledUsbChanged(m_enabledUsb);
    emit enabledFinalizeChanged(m_enabledFinalize);

    startDataChanged(parseTestParams(COLLAUDO_START));
    codeSpiIDChanged(parseTestParams(COLLAUDO_FLASH_SPI_RID));
    codeQSpiIDChanged(parseTestParams(COLLAUDO_FLASH_QSPI_RID));
    maskDipSwitchChanged(parseTestParams(COLLAUDO_DIP_SWITCH));
    maskCpuChanged(parseTestParams(COLLAUDO_CPU));
    maskFlashChanged(parseTestParams(COLLAUDO_FLASH));
    wifiDataChanged(parseTestParams(COLLAUDO_WIFI));
    rtcVerDataChanged(parseTestParams(COLLAUDO_RTC_VBAT));
    cloudDataChanged(parseTestParams(COLLAUDO_WRITE_CLOUD));
}

QString CSVFileWriter::parseTestParams(quint16 index, const bool commaFill)
{
    QString testParams = "";
    if(m_test[index].test_params)
    {
        testParams = "";
        for(uint8_t i=0; i<m_test[index].test_params->length(); i++)
        {
            if( m_test[index].test_params->at(i) != "" || commaFill)
            {
                testParams.append( m_test[index].test_params->at(i) );
                testParams.append( ", " );
            }
        }
        testParams.remove( testParams.length()-2, 2);
    }
    return testParams;
}


/******************************************************************************
 **** CSVFileWriter::getStartData
 */
QString CSVFileWriter::getStartData()
{
    return parseTestParams(COLLAUDO_START);
}
/*
 * CSVFileWriter::setStartData
 */
void CSVFileWriter::setStartData(const QString &value)
{
    QStringList list1 = value.split(QLatin1Char(':'));
    m_startData[ list1[0].toInt() ] = list1[1];

    delete m_test[COLLAUDO_START].test_params;
    m_test[COLLAUDO_START].test_params = nullptr;
    m_test[COLLAUDO_START].test_params = new QStringList();

    for(uint8_t i=0; i<2; i++)
        m_test[COLLAUDO_START].test_params->append(m_startData[i]);
}
/*
 * End COLLAUDO_START
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::getFileName
 */
QString CSVFileWriter::getCodeSpiID()
{
    return parseTestParams(COLLAUDO_FLASH_SPI_RID);
}
/*
 * CSVFileWriter::setFileName
 */
void CSVFileWriter::setCodeSpiID(const QString &value)
{
    QStringList list1 = value.split(QLatin1Char(':'));
    m_codeSpiID[ list1[0].toInt() ] = list1[1];

    delete m_test[COLLAUDO_FLASH_SPI_RID].test_params;
    m_test[COLLAUDO_FLASH_SPI_RID].test_params = nullptr;
    m_test[COLLAUDO_FLASH_SPI_RID].test_params = new QStringList();

    for(uint8_t i=0; i<5; i++)
        m_test[COLLAUDO_FLASH_SPI_RID].test_params->append(m_codeSpiID[i]);
}
/*
 * End COLLAUDO_FLASH_SPI_RID
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::getFileName
 */
QString CSVFileWriter::getCodeQSpiID()
{
    return parseTestParams(COLLAUDO_FLASH_QSPI_RID);
}
/*
 * CSVFileWriter::setFileName
 */
void CSVFileWriter::setCodeQSpiID(const QString &value)
{
    QStringList list1 = value.split(QLatin1Char(':'));
    //qDebug() << "cpp: codeSpiIDChanged changed:  " << value << " 0: " << list1[0] << " 1: " << list1[1];
    m_codeQSpiID[ list1[0].toInt() ] = list1[1];

    delete m_test[COLLAUDO_FLASH_QSPI_RID].test_params;
    m_test[COLLAUDO_FLASH_QSPI_RID].test_params = nullptr;
    m_test[COLLAUDO_FLASH_QSPI_RID].test_params = new QStringList();

    for(uint8_t i=0; i<5; i++)
        m_test[COLLAUDO_FLASH_QSPI_RID].test_params->append(m_codeQSpiID[i]);
}
/*
 * End COLLAUDO_FLASH_QSPI_RID
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::getMaskDipSwitch
 */
QString CSVFileWriter::getMaskDipSwitch()
{
    return parseTestParams(COLLAUDO_DIP_SWITCH);
}
/*
 * CSVFileWriter::setMaskDipSwitch
 */
void CSVFileWriter::setMaskDipSwitch(const QString &value)
{
    QStringList list1 = value.split(QLatin1Char(':'));
    qDebug() << "cpp: maskDipSwitchChanged changed:  " << value << " 0: " << list1[0] << " 1: " << list1[1];
    m_maskDipSwitch[ list1[0].toInt() ] = list1[1];

    delete m_test[COLLAUDO_DIP_SWITCH].test_params;
    m_test[COLLAUDO_DIP_SWITCH].test_params = nullptr;
    m_test[COLLAUDO_DIP_SWITCH].test_params = new QStringList();

    for(uint8_t i=0; i<4; i++)
        m_test[COLLAUDO_DIP_SWITCH].test_params->append(m_maskDipSwitch[i]);
}

/*
 * End COLLAUDO_DIP_SWITCH
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::getMaskCpu
 */
QString CSVFileWriter::getMaskCpu()
{
    return parseTestParams(COLLAUDO_CPU);
}
/*
 * CSVFileWriter::setMaskCpu
 */
void CSVFileWriter::setMaskCpu(const QString &value)
{
    QStringList list1 = value.split(QLatin1Char(':'));
    qDebug() << "cpp: setMaskCpu changed:  " << value << " 0: " << list1[0] << " 1: " << list1[1];
    m_maskCpu[ list1[0].toInt() ] = list1[1];

    delete m_test[COLLAUDO_CPU].test_params;
    m_test[COLLAUDO_CPU].test_params = nullptr;
    m_test[COLLAUDO_CPU].test_params = new QStringList();

    for(uint8_t i=0; i<5; i++)
        m_test[COLLAUDO_CPU].test_params->append(m_maskCpu[i]);
}

/*
 * End COLLAUDO_CPU
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::getMaskCpu
 */
QString CSVFileWriter::getMaskFlash()
{
    return parseTestParams(COLLAUDO_CPU);
}
/*
 * CSVFileWriter::setMaskFlash
 */
void CSVFileWriter::setMaskFlash(const QString &value)
{
    QStringList list1 = value.split(QLatin1Char(':'));
    m_maskFlash[ list1[0].toInt() ] = list1[1];

    delete m_test[COLLAUDO_FLASH].test_params;
    m_test[COLLAUDO_FLASH].test_params = nullptr;
    m_test[COLLAUDO_FLASH].test_params = new QStringList();

    for(uint8_t i=0; i<5; i++)
        m_test[COLLAUDO_FLASH].test_params->append(m_maskFlash[i]);
}

/*
 * End COLLAUDO_FLASH
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::getWifiData
 */
QString CSVFileWriter::getWifiData()
{
    return parseTestParams(COLLAUDO_WIFI);
}
/*
 * CSVFileWriter::setWifiData
 */
void CSVFileWriter::setWifiData(const QString &value)
{
    QStringList list1 = value.split(QLatin1Char(':'));
    qDebug() << "cpp: wifiDataChanged changed:  " << value << " 0: " << list1[0] << " 1: " << list1[1];
    m_wifiData[ list1[0].toInt() ] = list1[1];

    delete m_test[COLLAUDO_WIFI].test_params;
    m_test[COLLAUDO_WIFI].test_params = nullptr;
    m_test[COLLAUDO_WIFI].test_params = new QStringList();

    for(uint8_t i=0; i<3; i++)
        m_test[COLLAUDO_WIFI].test_params->append(m_wifiData[i]);
}
/*
 * End COLLAUDO_WIFI
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::getWifiData
 */
QString CSVFileWriter::getCloudData()
{
    return parseTestParams(COLLAUDO_WRITE_CLOUD);
}
/*
 * CSVFileWriter::setCloudData
 */
void CSVFileWriter::setCloudData(const QString &value)
{
    QStringList list1 = value.split(QLatin1Char(':'));
    qDebug() << "cpp: setCloudData changed:  " << value << " 0: " << list1[0] << " 1: " << list1[1];
    m_cloudData[ list1[0].toInt() ] = list1[1];

    delete m_test[COLLAUDO_WRITE_CLOUD].test_params;
    m_test[COLLAUDO_WRITE_CLOUD].test_params = nullptr;
    m_test[COLLAUDO_WRITE_CLOUD].test_params = new QStringList();

    for(uint8_t i=0; i<1; i++)
        m_test[COLLAUDO_WRITE_CLOUD].test_params->append(m_cloudData[i]);
}
/*
 * End COLLAUDO_WRITE_CLOUD
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::getWifiData
 */
QString CSVFileWriter::getRtcVerData()
{
    return parseTestParams(COLLAUDO_RTC_VBAT);
}
/*
 * CSVFileWriter::setRtcVerData
 */
void CSVFileWriter::setRtcVerData(const QString &value)
{
    QStringList list1 = value.split(QLatin1Char(':'));
    qDebug() << "cpp: setRtcVerData changed:  " << value << " 0: " << list1[0] << " 1: " << list1[1];
    m_rtcVerData[ list1[0].toInt() ] = list1[1];

    delete m_test[COLLAUDO_RTC_VBAT].test_params;
    m_test[COLLAUDO_RTC_VBAT].test_params = nullptr;
    m_test[COLLAUDO_RTC_VBAT].test_params = new QStringList();

    for(uint8_t i=0; i<2; i++)
        m_test[COLLAUDO_RTC_VBAT].test_params->append(m_rtcVerData[i]);
}
/*
 * End COLLAUDO_RTC_VBAT
 *****************************************************************************/


