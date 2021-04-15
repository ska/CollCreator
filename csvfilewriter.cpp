#include "csvfilewriter.h"

/*
 * CSVFileWriter::CSVFileWriter
 */
CSVFileWriter::CSVFileWriter(QObject *parent) : QObject(parent)
{
    m_enabledReadSpiID = false;
    m_enabledReadSpiID = false;
    m_enabledSpiRW = false;
    m_enabledReadQSpiID = false;
    m_enabledQSpiRW = false;
    m_enabledDisplay = false;
    m_enabledBacklight = false;
    m_enabledBuzzEst = false;
    m_enabledBuzzInt = false;
    m_enabledEncoder = false;
    m_enabledDipSwitch = false;
    m_enabledSD = false;
    m_enabledETH = false;
    m_enabledWifi = false;
    m_enabledModBus = false;
    m_enabledModBus2 = false;
    m_enabledCanBus = false;
    m_enabledEcsBus = false;
    m_enabledNtc = false;
    m_enabledAnalog = false;
    m_enabledI2CEE = false;
    m_enabledEthNtp = false;
    m_enabledEthMac = false;
    m_enabledUsb = false;
    m_enabledFinalize = false;


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
    file.close();
}

void CSVFileWriter::openFile(const QString &outpath)
{
    qDebug() << "OPEN FILE" << QSysInfo::machineHostName();
    QFile file("out.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;


    file.close();
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
 **** CSVFileWriter::isEnabledReadSpiID
 */
bool CSVFileWriter::isEnabledReadSpiID()
{
    return m_enabledReadSpiID;
}
/*
 * CSVFileWriter::setFileName
 */
void CSVFileWriter::setEnabledReadSpiID(const bool value)
{
    if (value == m_enabledReadSpiID)
        return;

    m_enabledReadSpiID = value;
    qDebug() << "cpp: enabledReadSpiIDChanged changed:  " << m_enabledReadSpiID;

    emit enabledReadSpiIDChanged();
}
/*
 * CSVFileWriter::getFileName
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
 **** CSVFileWriter::isEnabledSpiRW
 */
bool CSVFileWriter::isEnabledSpiRW()
{
    return m_enabledSpiRW;
}
/*
 * CSVFileWriter::setEnabledSpiRW
 */
void CSVFileWriter::setEnabledSpiRW(const bool value)
{
    if (value == m_enabledSpiRW)
        return;

    m_enabledSpiRW = value;
    qDebug() << "cpp: enabledSpiRW changed:  " << m_enabledSpiRW;

    //emit enabledSpiRW();
}
/*
 * End COLLAUDO_FLASH_SPI_RW
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledReadSpiID
 */
bool CSVFileWriter::isEnabledReadQSpiID()
{
    return m_enabledReadQSpiID;
}
/*
 * CSVFileWriter::setFileName
 */
void CSVFileWriter::setEnabledReadQSpiID(const bool value)
{
    if (value == m_enabledReadQSpiID)
        return;

    m_enabledReadQSpiID = value;
    qDebug() << "cpp: enabledReadQSpiIDChanged changed:  " << m_enabledReadQSpiID;

    emit enabledReadQSpiIDChanged();
}
/*
 * CSVFileWriter::getFileName
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
 **** CSVFileWriter::isEnabledQSpiRW
 */
bool CSVFileWriter::isEnabledQSpiRW()
{
    return m_enabledQSpiRW;
}
/*
 * CSVFileWriter::setEnabledQSpiRW
 */
void CSVFileWriter::setEnabledQSpiRW(const bool value)
{
    if (value == m_enabledQSpiRW)
        return;
    m_enabledQSpiRW = value;

    qDebug() << "cpp: enabledQSpiRW changed:  " << m_enabledQSpiRW;
    //emit enabledQSpiRW();
}
/*
 * End COLLAUDO_FLASH_QSPI_RW
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledDisplay
 */
bool CSVFileWriter::isEnabledDisplay()
{
    return m_enabledDisplay;
}
/*
 * CSVFileWriter::setEnabledDisplay
 */
void CSVFileWriter::setEnabledDisplay(const bool value)
{
    if (value == m_enabledDisplay)
        return;
    m_enabledDisplay = value;

    qDebug() << "cpp: enabledDisplayChanged changed:  " << m_enabledDisplay;
    //emit enabledDisplayChanged();
}
/*
 * End COLLAUDO_DISPLAY_TOUCH
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledBacklight
 */
bool CSVFileWriter::isEnabledBacklight()
{
    return m_enabledBacklight;
}
/*
 * CSVFileWriter::setEnabledBacklight
 */
void CSVFileWriter::setEnabledBacklight(const bool value)
{
    if (value == m_enabledBacklight)
        return;
    m_enabledBacklight = value;

    qDebug() << "cpp: enabledBacklightChanged changed:  " << m_enabledBacklight;
    //emit enabledBacklightChanged();
}
/*
 * End COLLAUDO_BACKLIGHT
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledBuzzEst
 */
bool CSVFileWriter::isEnabledBuzzEst()
{
    return m_enabledBuzzEst;
}
/*
 * CSVFileWriter::setEnabledBuzzEst
 */
void CSVFileWriter::setEnabledBuzzEst(const bool value)
{
    if (value == m_enabledBuzzEst)
        return;
    m_enabledBuzzEst = value;

    qDebug() << "cpp: setEnabledBuzzEst changed:  " << m_enabledBuzzEst;
    emit enabledBuzzEstChanged();
}
/*
 * End COLLAUDO_BUZZER_ESTERNO
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledBuzzInt
 */
bool CSVFileWriter::isEnabledBuzzInt()
{
    return m_enabledBuzzInt;
}
/*
 * CSVFileWriter::setEnabledBuzzInt
 */
void CSVFileWriter::setEnabledBuzzInt(const bool value)
{
    if (value == m_enabledBuzzInt)
        return;
    m_enabledBuzzInt = value;

    qDebug() << "cpp: enabledBuzzIntChanged changed:  " << m_enabledBuzzInt;
    emit enabledBuzzIntChanged();
}
/*
 * End COLLAUDO_BUZZER_INTERNO
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledEncoder
 */
bool CSVFileWriter::isEnabledEncoder()
{
    return m_enabledEncoder;
}
/*
 * CSVFileWriter::setEnabledEncoder
 */
void CSVFileWriter::setEnabledEncoder(const bool value)
{
    if (value == m_enabledEncoder)
        return;
    m_enabledEncoder = value;

    qDebug() << "cpp: enabledEncoderChanged changed:  " << m_enabledEncoder;
    emit enabledEncoderChanged();
}
/*
 * End COLLAUDO_ENCODER
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledDipSwitch
 */
bool CSVFileWriter::isEnabledDipSwitch()
{
    return m_enabledDipSwitch;
}
/*
 * CSVFileWriter::setEnabledDipSwitch
 */
void CSVFileWriter::setEnabledDipSwitch(const bool value)
{
    if (value == m_enabledDipSwitch)
        return;
    m_enabledDipSwitch = value;

    qDebug() << "cpp: enabledDipSwitchChanged changed:  " << m_enabledDipSwitch;
    //emit enabledDipSwitchChanged();
}

/*
 * CSVFileWriter::getMaskDipSwitch
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
 **** CSVFileWriter::isEnabledCpu
 */
bool CSVFileWriter::isEnabledCpu()
{
    return m_enabledCpu;
}
/*
 * CSVFileWriter::setEnabledCpu
 */
void CSVFileWriter::setEnabledCpu(const bool value)
{
    if (value == m_enabledCpu)
        return;
    m_enabledCpu = value;

    qDebug() << "cpp: enabledCpuChanged changed:  " << m_enabledCpu;
    emit enabledCpuChanged();
}

/*
 * CSVFileWriter::getMaskCpu
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
 **** CSVFileWriter::isEnabledFlash
 */
bool CSVFileWriter::isEnabledFlash()
{
    return m_enabledFlash;
}
/*
 * CSVFileWriter::setEnabledFlash
 */
void CSVFileWriter::setEnabledFlash(const bool value)
{
    if (value == m_enabledFlash)
        return;
    m_enabledFlash = value;

    qDebug() << "cpp: enabledFlashChanged changed:  " << m_enabledFlash;
    emit enabledFlashChanged();
}

/*
 * CSVFileWriter::getMaskCpu
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
    emit maskFlashChanged();
}

/*
 * End COLLAUDO_FLASH
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledSD
 */
bool CSVFileWriter::isEnabledSD()
{
    return m_enabledSD;
}
/*
 * CSVFileWriter::setEnabledSD
 */
void CSVFileWriter::setEnabledSD(const bool value)
{
    if (value == m_enabledSD)
        return;
    m_enabledSD = value;

    qDebug() << "cpp: enabledSDChanged changed:  " << m_enabledSD;
    emit enabledSDChanged();
}
/*
 * End COLLAUDO_SD
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledETH
 */
bool CSVFileWriter::isEnabledETH()
{
    return m_enabledETH;
}
/*
 * CSVFileWriter::setEnabledETH
 */
void CSVFileWriter::setEnabledETH(const bool value)
{
    if (value == m_enabledETH)
        return;
    m_enabledETH = value;

    qDebug() << "cpp: enabledETHChanged changed:  " << m_enabledETH;
    emit enabledETHChanged();
}
/*
 * End COLLAUDO_ETHERNET
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledWifi
 */
bool CSVFileWriter::isEnabledWifi()
{
    return m_enabledWifi;
}
/*
 * CSVFileWriter::setEnabledWifi
 */
void CSVFileWriter::setEnabledWifi(const bool value)
{
    if (value == m_enabledWifi)
        return;

    m_enabledWifi = value;
    qDebug() << "cpp: enabledWifiChanged changed:  " << m_enabledWifi;

    emit enabledWifiChanged();
}
/*
 * CSVFileWriter::getWifiData
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
    emit wifiDataChanged();
}
/*
 * End COLLAUDO_FLASH_QSPI_RID
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledModBus
 */
bool CSVFileWriter::isEnabledModBus()
{
    return m_enabledModBus;
}
/*
 * CSVFileWriter::setEnabledModBus
 */
void CSVFileWriter::setEnabledModBus(const bool value)
{
    if (value == m_enabledModBus)
        return;
    m_enabledModBus = value;

    qDebug() << "cpp: enabledModBusChanged changed:  " << m_enabledModBus;
    emit enabledModBusChanged();
}
/*
 * End COLLAUDO_MODBUS
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledModBus2
 */
bool CSVFileWriter::isEnabledModBus2()
{
    return m_enabledModBus2;
}
/*
 * CSVFileWriter::setEnabledModBus2
 */
void CSVFileWriter::setEnabledModBus2(const bool value)
{
    if (value == m_enabledModBus2)
        return;
    m_enabledModBus2 = value;

    qDebug() << "cpp: enabledModBus2Changed changed:  " << m_enabledModBus2;
    emit enabledModBus2Changed();
}
/*
 * End COLLAUDO_MODBUS2
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledCanBus
 */
bool CSVFileWriter::isEnabledCanBus()
{
    return m_enabledCanBus;
}
/*
 * CSVFileWriter::setEnabledCanBus
 */
void CSVFileWriter::setEnabledCanBus(const bool value)
{
    if (value == m_enabledCanBus)
        return;
    m_enabledCanBus = value;

    qDebug() << "cpp: enabledCanBusChanged changed:  " << m_enabledCanBus;
    emit enabledCanBusChanged();
}
/*
 * End COLLAUDO_CAN
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledEcsBus
 */
bool CSVFileWriter::isEnabledEcsBus()
{
    return m_enabledEcsBus;
}
/*
 * CSVFileWriter::setEnabledEcsBus
 */
void CSVFileWriter::setEnabledEcsBus(const bool value)
{
    if (value == m_enabledEcsBus)
        return;
    m_enabledEcsBus = value;

    qDebug() << "cpp: enabledEcsBusChanged changed:  " << m_enabledEcsBus;
    emit enabledEcsBusChanged();
}
/*
 * End COLLAUDO_ECSBUS
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledNtc
 */
bool CSVFileWriter::isEnabledNtc()
{
    return m_enabledNtc;
}
/*
 * CSVFileWriter::setEnabledNtc
 */
void CSVFileWriter::setEnabledNtc(const bool value)
{
    if (value == m_enabledNtc)
        return;
    m_enabledNtc = value;

    qDebug() << "cpp: enabledNtcChanged changed:  " << m_enabledNtc;
    emit enabledNtcChanged();
}
/*
 * End COLLAUDO_NTC
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledAnalog
 */
bool CSVFileWriter::isEnabledAnalog()
{
    return m_enabledAnalog;
}
/*
 * CSVFileWriter::setEnabledAnalog
 */
void CSVFileWriter::setEnabledAnalog(const bool value)
{
    if (value == m_enabledAnalog)
        return;
    m_enabledAnalog = value;

    qDebug() << "cpp: enabledAnalogChanged changed:  " << m_enabledAnalog;
    emit enabledAnalogChanged();
}
/*
 * End COLLAUDO_ANALOGICHE
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledI2CEE
 */
bool CSVFileWriter::isEnabledI2CEE()
{
    return m_enabledI2CEE;
}
/*
 * CSVFileWriter::setEnabledI2CEE
 */
void CSVFileWriter::setEnabledI2CEE(const bool value)
{
    if (value == m_enabledI2CEE)
        return;
    m_enabledI2CEE = value;

    qDebug() << "cpp: enabledI2CEEChanged changed:  " << m_enabledI2CEE;
    emit enabledI2CEEChanged();
}
/*
 * End COLLAUDO_I2C_EEPROM
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledEthNtp
 */
bool CSVFileWriter::isEnabledEthNtp()
{
    return m_enabledEthNtp;
}
/*
 * CSVFileWriter::setEnabledEthNtp
 */
void CSVFileWriter::setEnabledEthNtp(const bool value)
{
    if (value == m_enabledEthNtp)
        return;
    m_enabledEthNtp = value;

    qDebug() << "cpp: enabledEthNtpChanged changed:  " << m_enabledEthNtp;
    emit enabledEthNtpChanged();
}
/*
 * End COLLAUDO_SET_DATE_FROM_NTP_ETH
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledEthMac
 */
bool CSVFileWriter::isEnabledEthMac()
{
    return m_enabledEthMac;
}
/*
 * CSVFileWriter::setEnabledEthMac
 */
void CSVFileWriter::setEnabledEthMac(const bool value)
{
    if (value == m_enabledEthMac)
        return;
    m_enabledEthMac = value;

    qDebug() << "cpp: enabledEthMacChanged changed:  " << m_enabledEthMac;
    emit enabledEthMacChanged();
}
/*
 * End COLLAUDO_WRITE_MAC
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledUsb
 */
bool CSVFileWriter::isEnabledUsb()
{
    return m_enabledUsb;
}
/*
 * CSVFileWriter::setEnabledUsb
 */
void CSVFileWriter::setEnabledUsb(const bool value)
{
    if (value == m_enabledUsb)
        return;
    m_enabledUsb = value;

    qDebug() << "cpp: enabledUsbChanged changed:  " << m_enabledUsb;
    emit enabledUsbChanged();
}
/*
 * End COLLAUDO_USB
 *****************************************************************************/

/******************************************************************************
 **** CSVFileWriter::isEnabledFinalize
 */
bool CSVFileWriter::isEnabledFinalize()
{
    return m_enabledFinalize;
}
/*
 * CSVFileWriter::setEnabledFinalize
 */
void CSVFileWriter::setEnabledFinalize(const bool value)
{
    if (value == m_enabledFinalize)
        return;
    m_enabledFinalize = value;

    qDebug() << "cpp: enabledFinalizeChanged changed:  " << m_enabledFinalize;
    emit enabledFinalizeChanged();
}
/*
 * End COLLAUDO_FINALIZE
 *****************************************************************************/

