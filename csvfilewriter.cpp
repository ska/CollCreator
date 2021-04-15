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
    m_enabledI2CEE		= false;
    m_enabledEthNtp		= false;
    m_enabledEthMac		= false;
    m_enabledUsb		= false;
    m_enabledFinalize	= false;

    for(uint8_t i=0; i<COLLAUDO_END_TESTS; i++)
    {
        m_test[i].test_name = "";
        m_test[i].test_en_var = NULL;
        m_test[i].test_params = "";
    }

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
    m_test[COLLAUDO_I2C_EEPROM].test_en_var = &m_enabledI2CEE;
    m_test[COLLAUDO_SET_DATE_FROM_NTP_ETH].test_en_var = &m_enabledEthNtp;
    m_test[COLLAUDO_WRITE_MAC].test_en_var = &m_enabledEthMac;
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

    //const void *pfnSignal = nullptr;
    //pfnSignal = SIGNAL(enabledReadSpiIDChanged());
    //m_test[COLLAUDO_FLASH_SPI_RID].test_signal = &CSVFileWriter::enabledReadSpiIDChanged;
    //m_test[COLLAUDO_FLASH_SPI_RID].pfnSignal = &CSVFileWriter::enabledReadSpiIDChanged;

}


/******************************************************************************
 **** CSVFileWriter::getStartData
 */
void CSVFileWriter::generateFile(const QString &outpath)
{
    //QByteArray pippo = QSysInfo::machineUniqueId();
    qDebug() << "GENERATE FILE" << QSysInfo::machineHostName();

    QFile file("out.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << "# File generated with Alpha5 tool\n";
    out << "# On PC " << QSysInfo::machineHostName() << " \n";

    if( !startData[1].isEmpty() )
        out << "COLLAUDO_START,  " << startData[0] << ",  " << startData[1] << "\n";
    else if( !startData[0].isEmpty() )
        out << "COLLAUDO_START,  " << startData[0]  << "\n";
    else
        out << "COLLAUDO_START\n";

    if(m_enabledReadSpiID)
    {
        out << "COLLAUDO_FLASH_SPI_RID";
        for(uint8_t i = 0; i<5; i++)
            if(!m_codeSpiID[i].isEmpty())
                out << ", " << m_codeSpiID[i];
        out << "\n";
    }

    if(m_enabledSpiRW)
        out << "COLLAUDO_FLASH_SPI_RW \n";

    if(m_enabledReadQSpiID)
    {
        out << "COLLAUDO_FLASH_QSPI_RID";
        for(uint8_t i = 0; i<5; i++)
            if(!m_codeQSpiID[i].isEmpty())
                out << ", " << m_codeQSpiID[i];
        out << "\n";
    }

    if(m_enabledQSpiRW)
        out << "COLLAUDO_FLASH_QSPI_RW\n";

    if(m_enabledDisplay)
        out << "COLLAUDO_DISPLAY_TOUCH\n";

    if(m_enabledBacklight)
        out << "COLLAUDO_BACKLIGHT\n";

    if(m_enabledBuzzEst)
        out << "COLLAUDO_BUZZER_ESTERNO\n";

    if(m_enabledBuzzInt)
        out << "COLLAUDO_BUZZER_INTERNO\n";

    if(m_enabledEncoder)
        out << "COLLAUDO_ENCODER\n";

    if(m_enabledDipSwitch)
    {
        out << "COLLAUDO_DIP_SWITCH";
        for(uint8_t i = 0; i<4; i++)
            if(!m_maskDipSwitch[i].isEmpty())
                out << ", " << m_maskDipSwitch[i];
            else
                out << ", 0";
        out << "\n";
    }

    if(m_enabledCpu)
    {
        out << "COLLAUDO_CPU";
        for(uint8_t i = 0; i<5; i++)
            if(!m_maskCpu[i].isEmpty())
                out << ", " << m_maskCpu[i];
        out << "\n";
    }

    if(m_enabledFlash)
    {
        out << "COLLAUDO_FLASH";
        for(uint8_t i = 0; i<5; i++)
            if(!m_maskFlash[i].isEmpty())
                out << ", " << m_maskFlash[i];
        out << "\n";
    }

    if(m_enabledSD)
        out << "COLLAUDO_SD\n";
    if(m_enabledETH)
        out << "COLLAUDO_ETHERNET\n";
    if(m_enabledWifi)
        out << "COLLAUDO_WIFI\n";
    if(m_enabledModBus)
        out << "COLLAUDO_MODBUS\n";
    if(m_enabledModBus2)
        out << "COLLAUDO_MODBUS2\n";
    if(m_enabledCanBus)
        out << "COLLAUDO_CAN\n";
    if(m_enabledEcsBus)
        out << "COLLAUDO_ECSBUS\n";
    if(m_enabledNtc)
        out << "COLLAUDO_NTC\n";
    if(m_enabledAnalog)
        out << "COLLAUDO_ANALOGICHE\n";
    if(m_enabledI2CEE)
        out << "COLLAUDO_I2C_EEPROM\n";
    if(m_enabledEthNtp)
        out << "COLLAUDO_SET_DATE_FROM_NTP_ETH\n";
    if(m_enabledEthMac)
        out << "COLLAUDO_WRITE_MAC\n";
    if(m_enabledUsb)
        out << "COLLAUDO_USB\n";
    if(m_enabledFinalize)
        out << "COLLAUDO_FINALIZE\n";

    file.close();
}

void CSVFileWriter::openFile(const QString &outpath)
{
    qDebug() << "OPEN FILE" << QSysInfo::machineHostName();

    QFile file("out.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    for(uint8_t i=0; i<COLLAUDO_END_TESTS; i++)
        if(m_test[i].test_en_var)
            *(m_test[i].test_en_var) = false;

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString testName;
        QString testParams = "";
        QString line = in.readLine();
        if(line[0] == '#')
            continue;

        qDebug() << "line " << line;
        QStringList fields = line.split(",");
        testName = fields.takeFirst().trimmed();
        if(fields.size())
        {
            qDebug() << "fields.size() " << fields.size();
            testParams = fields.join(",");
        }

        for(uint8_t i=0; i<COLLAUDO_END_TESTS; i++)
        {
            if(m_test[i].test_name == testName)
            {
                if(m_test[i].test_en_var)
                    *(m_test[i].test_en_var) = true;
                m_test[i].test_params = testParams;
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
    emit enabledI2CEEChanged(m_enabledI2CEE);
    emit enabledEthNtpChanged(m_enabledEthNtp);
    emit enabledEthMacChanged(m_enabledEthMac);
    emit enabledUsbChanged(m_enabledUsb);
    emit enabledFinalizeChanged(m_enabledFinalize);
}


/******************************************************************************
 * CSVFileWriter::setFileName
 */
void CSVFileWriter::setStartData(const QString &value)
{
    QStringList list1 = value.split(QLatin1Char(':'));
    //qDebug() << "cpp: codeSpiIDChanged changed:  " << value << " 0: " << list1[0] << " 1: " << list1[1];
    startData[ list1[0].toInt() ] = list1[1];
    //emit startDataChanged();
}
/*
 * End COLLAUDO_START
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::getFileName
 */
QString CSVFileWriter::getCodeSpiID()
{
    return "0x00c22019, 0x0020BA20";
}
/*
 * CSVFileWriter::setFileName
 */
void CSVFileWriter::setCodeSpiID(const QString &value)
{
    QStringList list1 = value.split(QLatin1Char(':'));
    //qDebug() << "cpp: codeSpiIDChanged changed:  " << value << " 0: " << list1[0] << " 1: " << list1[1];
    m_codeSpiID[ list1[0].toInt() ] = list1[1];
    //emit codeSpiIDChanged();
}
/*
 * End COLLAUDO_FLASH_SPI_RID
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::getFileName
 */
QString CSVFileWriter::getCodeQSpiID()
{
    return "0x00c22019, 0x0020BA20";
}
/*
 * CSVFileWriter::setFileName
 */
void CSVFileWriter::setCodeQSpiID(const QString &value)
{
    QStringList list1 = value.split(QLatin1Char(':'));
    //qDebug() << "cpp: codeSpiIDChanged changed:  " << value << " 0: " << list1[0] << " 1: " << list1[1];
    m_codeQSpiID[ list1[0].toInt() ] = list1[1];
    //emit codeQSpiIDChanged();
}
/*
 * End COLLAUDO_FLASH_QSPI_RID
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::getMaskDipSwitch
 */
QString CSVFileWriter::getMaskDipSwitch()
{
    qDebug() << "cpp: getMaskDipSwitch";
    return "0, 1, 0, 1";
}
/*
 * CSVFileWriter::setMaskDipSwitch
 */
void CSVFileWriter::setMaskDipSwitch(const QString &value)
{
    QStringList list1 = value.split(QLatin1Char(':'));
    qDebug() << "cpp: maskDipSwitchChanged changed:  " << value << " 0: " << list1[0] << " 1: " << list1[1];
    m_maskDipSwitch[ list1[0].toInt() ] = list1[1];
    //emit maskDipSwitchChanged();
}

/*
 * End COLLAUDO_DIP_SWITCH
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::getMaskCpu
 */
QString CSVFileWriter::getMaskCpu()
{
    qDebug() << "cpp: getMaskCpu";
    return "";
}
/*
 * CSVFileWriter::setMaskCpu
 */
void CSVFileWriter::setMaskCpu(const QString &value)
{
    QStringList list1 = value.split(QLatin1Char(':'));
    qDebug() << "cpp: setMaskCpu changed:  " << value << " 0: " << list1[0] << " 1: " << list1[1];
    m_maskCpu[ list1[0].toInt() ] = list1[1];
    emit maskCpuChanged();
}

/*
 * End COLLAUDO_CPU
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::getMaskCpu
 */
QString CSVFileWriter::getMaskFlash()
{
    qDebug() << "cpp: getMaskFlash";
    return "";
}
/*
 * CSVFileWriter::setMaskFlash
 */
void CSVFileWriter::setMaskFlash(const QString &value)
{
    QStringList list1 = value.split(QLatin1Char(':'));
    qDebug() << "cpp: setMaskFlash changed:  " << value << " 0: " << list1[0] << " 1: " << list1[1];
    m_maskFlash[ list1[0].toInt() ] = list1[1];
    //emit maskFlashChanged();
}

/*
 * End COLLAUDO_FLASH
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::getWifiData
 */
QString CSVFileWriter::getWifiData()
{
    return "SsidGuest, PassWord!23";
}
/*
 * CSVFileWriter::setWifiData
 */
void CSVFileWriter::setWifiData(const QString &value)
{
    QStringList list1 = value.split(QLatin1Char(':'));
    qDebug() << "cpp: wifiDataChanged changed:  " << value << " 0: " << list1[0] << " 1: " << list1[1];
    m_wifiData[ list1[0].toInt() ] = list1[1];
    //emit wifiDataChanged();
}
/*
 * End COLLAUDO_FLASH_QSPI_RID
 *****************************************************************************/

