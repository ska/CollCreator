#ifndef CSVFILEWRITER_H
#define CSVFILEWRITER_H

#include <QObject>
#include <QDebug>
#include <QUrl>
#include <QFile>
#include <QDir>

class CSVFileWriter: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString pippo WRITE generateFile)
    Q_PROPERTY(QString pluto WRITE openFile)

    /* COLLAUDO_START */
    Q_PROPERTY(QString startData WRITE setStartData)
    /* COLLAUDO_FLASH_SPI_RID */
    Q_PROPERTY(bool enabledReadSpiID READ isEnabledReadSpiID WRITE setEnabledReadSpiID NOTIFY enabledReadSpiIDChanged)
    Q_PROPERTY(QString codeSpiID  READ getCodeSpiID  WRITE setCodeSpiID  NOTIFY codeSpiIDChanged)
    /* COLLAUDO_FLASH_SPI_RW */
    Q_PROPERTY(bool enabledSpiRW READ isEnabledSpiRW WRITE setEnabledSpiRW NOTIFY enabledSpiRWChanged)
    /* COLLAUDO_FLASH_QSPI_RID */
    Q_PROPERTY(bool enabledReadQSpiID READ isEnabledReadQSpiID WRITE setEnabledReadQSpiID NOTIFY enabledReadQSpiIDChanged)
    Q_PROPERTY(QString codeQSpiID  READ getCodeQSpiID  WRITE setCodeQSpiID  NOTIFY codeQSpiIDChanged)
    /* COLLAUDO_FLASH_QSPI_RW */
    Q_PROPERTY(bool enabledQSpiRW READ isEnabledQSpiRW WRITE setEnabledQSpiRW NOTIFY enabledQSpiRWChanged)
    /* COLLAUDO_DISPLAY_TOUCH */
    Q_PROPERTY(bool enabledDisplay READ isEnabledDisplay WRITE setEnabledDisplay NOTIFY enabledDisplayChanged)
    /* COLLAUDO_BACKLIGHT */
    Q_PROPERTY(bool enabledBacklight READ isEnabledBacklight WRITE setEnabledBacklight NOTIFY enabledBacklightChanged)
    /* COLLAUDO_BUZZER_ESTERNO */
    Q_PROPERTY(bool enabledBuzzEst READ isEnabledBuzzEst WRITE setEnabledBuzzEst NOTIFY enabledBuzzEstChanged)
    /* COLLAUDO_BUZZER_INTERNO */
    Q_PROPERTY(bool enabledBuzzInt READ isEnabledBuzzInt WRITE setEnabledBuzzInt NOTIFY enabledBuzzIntChanged)
    /* COLLAUDO_ENCODER */
    Q_PROPERTY(bool enabledEncoder READ isEnabledEncoder WRITE setEnabledEncoder NOTIFY enabledEncoderChanged)
    /* COLLAUDO_DIP_SWITCH */
    Q_PROPERTY(bool enabledDipSwitch READ isEnabledDipSwitch WRITE setEnabledDipSwitch NOTIFY enabledDipSwitchChanged)
    Q_PROPERTY(QString maskDipSwitch  READ getMaskDipSwitch  WRITE setMaskDipSwitch  NOTIFY maskDipSwitchChanged)
    /* COLLAUDO_CPU */
    Q_PROPERTY(bool enabledCpu READ isEnabledCpu WRITE setEnabledCpu NOTIFY enabledCpuChanged)
    Q_PROPERTY(QString maskCpu  READ getMaskCpu  WRITE setMaskCpu  NOTIFY maskCpuChanged)
    /* COLLAUDO_FLASH */
    Q_PROPERTY(bool enabledFlash READ isEnabledFlash WRITE setEnabledFlash NOTIFY enabledFlashChanged)
    Q_PROPERTY(QString maskFlash READ getMaskFlash WRITE setMaskFlash NOTIFY maskFlashChanged)
    /* COLLAUDO_SD */
    Q_PROPERTY(bool enabledSD READ isEnabledSD WRITE setEnabledSD NOTIFY enabledSDChanged)
    /* COLLAUDO_ETHERNET */
    Q_PROPERTY(bool enabledETH READ isEnabledETH WRITE setEnabledETH NOTIFY enabledETHChanged)
    /* COLLAUDO_WIFI */
    Q_PROPERTY(bool enabledWifi READ isEnabledWifi WRITE setEnabledWifi NOTIFY enabledWifiChanged)
    Q_PROPERTY(QString wifiData READ getWifiData WRITE setWifiData  NOTIFY wifiDataChanged)
    /* COLLAUDO_MODBUS */
    Q_PROPERTY(bool enabledModBus READ isEnabledModBus WRITE setEnabledModBus NOTIFY enabledModBusChanged)
    /* COLLAUDO_MODBUS2 */
    Q_PROPERTY(bool enabledModBus2 READ isEnabledModBus2 WRITE setEnabledModBus2 NOTIFY enabledModBus2Changed)
    /* COLLAUDO_CAN */
    Q_PROPERTY(bool enabledCanBus READ isEnabledCanBus WRITE setEnabledCanBus NOTIFY enabledCanBusChanged)
    /* COLLAUDO_ECSBUS */
    Q_PROPERTY(bool enabledEcsBus READ isEnabledEcsBus WRITE setEnabledEcsBus NOTIFY enabledEcsBusChanged)
    /* COLLAUDO_NTC */
    Q_PROPERTY(bool enabledNtc READ isEnabledNtc WRITE setEnabledNtc NOTIFY enabledNtcChanged)
    /* COLLAUDO_ANALOGICHE */
    Q_PROPERTY(bool enabledAnalog READ isEnabledAnalog WRITE setEnabledAnalog NOTIFY enabledAnalogChanged)
    /* COLLAUDO_RTC_VBAT */
    /* COLLAUDO_I2C_EEPROM */
    Q_PROPERTY(bool enabledI2CEE READ isEnabledI2CEE WRITE setEnabledI2CEE NOTIFY enabledI2CEEChanged)
    /* COLLAUDO_SET_DATE_FROM_NTP_ETH */
    Q_PROPERTY(bool enabledEthNtp READ isEnabledEthNtp WRITE setEnabledEthNtp NOTIFY enabledEthNtpChanged)
    /* COLLAUDO_WRITE_MAC */
    Q_PROPERTY(bool enabledEthMac READ isEnabledEthMac WRITE setEnabledEthMac NOTIFY enabledEthMacChanged)
    /* COLLAUDO_WRITE_CLOUD */
    /* COLLAUDO_USB */
    Q_PROPERTY(bool enabledUsb READ isEnabledUsb WRITE setEnabledUsb NOTIFY enabledUsbChanged)
    /* COLLAUDO_FLASH_QSPI_PRG */
    /* COLLAUDO_FLASH_QSPI_DEL */
    /* COLLAUDO_FLASH_SPI_WBIN */
    /* COLLAUDO_FLASH_SPI_DEL */
    /* COLLAUDO_FINALIZE */
    Q_PROPERTY(bool enabledFinalize READ isEnabledFinalize WRITE setEnabledFinalize NOTIFY enabledFinalizeChanged)

public:
    CSVFileWriter(QObject *parent = nullptr);
    void generateFile(const QString &outpath);
    void openFile(const QString &outpath);

    void setStartData(const QString &value);
    bool isEnabledReadSpiID();
    void setEnabledReadSpiID(const bool value);
    QString getCodeSpiID();
    void setCodeSpiID(const QString &value);
    bool isEnabledSpiRW();
    void setEnabledSpiRW(const bool value);
    bool isEnabledReadQSpiID();
    void setEnabledReadQSpiID(const bool value);
    QString getCodeQSpiID();
    void setCodeQSpiID(const QString &value);
    bool isEnabledQSpiRW();
    void setEnabledQSpiRW(const bool value);
    bool isEnabledDisplay();
    void setEnabledDisplay(const bool value);
    bool isEnabledBacklight();
    void setEnabledBacklight(const bool value);
    bool isEnabledBuzzEst();
    void setEnabledBuzzEst(const bool value);
    bool isEnabledBuzzInt();
    void setEnabledBuzzInt(const bool value);
    bool isEnabledEncoder();
    void setEnabledEncoder(const bool value);
    bool isEnabledDipSwitch();
    void setEnabledDipSwitch(const bool value);
    QString getMaskDipSwitch();
    void setMaskDipSwitch(const QString &value);
    bool isEnabledCpu();
    void setEnabledCpu(const bool value);
    QString getMaskCpu();
    void setMaskCpu(const QString &value);
    /* COLLAUDO_FLASH */
    bool isEnabledFlash();
    void setEnabledFlash(const bool value);
    QString getMaskFlash();
    void setMaskFlash(const QString &value);
    bool isEnabledSD();
    void setEnabledSD(const bool value);
    bool isEnabledETH();
    void setEnabledETH(const bool value);
    bool isEnabledWifi();
    void setEnabledWifi(const bool value);
    QString getWifiData();
    void setWifiData(const QString &value);
    bool isEnabledModBus();
    void setEnabledModBus(const bool value);
    bool isEnabledModBus2();
    void setEnabledModBus2(const bool value);
    bool isEnabledCanBus();
    void setEnabledCanBus(const bool value);
    bool isEnabledEcsBus();
    void setEnabledEcsBus(const bool value);
    bool isEnabledNtc();
    void setEnabledNtc(const bool value);
    bool isEnabledAnalog();
    void setEnabledAnalog(const bool value);
    bool isEnabledI2CEE();
    void setEnabledI2CEE(const bool value);
    bool isEnabledEthNtp();
    void setEnabledEthNtp(const bool value);
    bool isEnabledEthMac();
    void setEnabledEthMac(const bool value);
    bool isEnabledUsb();
    void setEnabledUsb(const bool value);
    bool isEnabledFinalize();
    void setEnabledFinalize(const bool value);

signals:
    void enabledReadSpiIDChanged();
    void codeSpiIDChanged();
    void enabledSpiRWChanged();
    void enabledReadQSpiIDChanged();
    void codeQSpiIDChanged();
    void enabledQSpiRWChanged();
    void enabledDisplayChanged();
    void enabledBacklightChanged();
    void enabledBuzzEstChanged();
    void enabledBuzzIntChanged();
    void enabledEncoderChanged();
    void enabledDipSwitchChanged();
    void maskDipSwitchChanged();
    void enabledCpuChanged();
    void maskCpuChanged();
    void enabledFlashChanged();
    void maskFlashChanged();
    void enabledSDChanged();
    void enabledETHChanged();
    void enabledWifiChanged();
    void wifiDataChanged();
    void enabledModBusChanged();
    void enabledModBus2Changed();
    void enabledCanBusChanged();
    void enabledEcsBusChanged();
    void enabledNtcChanged();
    void enabledAnalogChanged();
    void enabledI2CEEChanged();
    void enabledEthNtpChanged();
    void enabledEthMacChanged();
    void enabledUsbChanged();
    void enabledFinalizeChanged();

private:    
    QString startData[2];
    bool m_enabledReadSpiID;
    QString m_codeSpiID[5];
    bool m_enabledSpiRW;
    bool m_enabledReadQSpiID;
    QString m_codeQSpiID[5];
    bool m_enabledQSpiRW;
    bool m_enabledDisplay;
    bool m_enabledBacklight;
    bool m_enabledBuzzEst;
    bool m_enabledBuzzInt;
    bool m_enabledEncoder;
    bool m_enabledDipSwitch;
    QString m_maskDipSwitch[4];
    bool m_enabledCpu;
    QString m_maskCpu[5];
    bool m_enabledFlash;
    QString m_maskFlash[5];
    bool m_enabledSD;
    bool m_enabledETH;
    bool m_enabledWifi;
    QString m_wifiData[3];
    bool m_enabledModBus;
    bool m_enabledModBus2;
    bool m_enabledCanBus;
    bool m_enabledEcsBus;
    bool m_enabledNtc;
    bool m_enabledAnalog;
    bool m_enabledI2CEE;
    bool m_enabledEthNtp;
    bool m_enabledEthMac;
    bool m_enabledUsb;
    bool m_enabledFinalize;


};

#endif // CSVFILEWRITER_H
