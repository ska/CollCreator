#ifndef CSVFILEWRITER_H
#define CSVFILEWRITER_H

#include <QObject>
#include <QDebug>
#include <QUrl>
#include <QFile>
#include <QDir>

enum {
    COLLAUDO_START,
    COLLAUDO_FLASH_SPI_RID,
    COLLAUDO_FLASH_SPI_RW,
    COLLAUDO_FLASH_QSPI_RID,
    COLLAUDO_FLASH_QSPI_RW,
    COLLAUDO_DISPLAY_TOUCH,
    COLLAUDO_BACKLIGHT,
    COLLAUDO_BUZZER_ESTERNO,
    COLLAUDO_BUZZER_INTERNO,
    COLLAUDO_ENCODER,
    COLLAUDO_DIP_SWITCH,
    COLLAUDO_CPU,
    COLLAUDO_FLASH,
    COLLAUDO_SD,
    COLLAUDO_ETHERNET,
    COLLAUDO_WIFI,
    COLLAUDO_MODBUS,
    COLLAUDO_MODBUS2,
    COLLAUDO_CAN,
    COLLAUDO_ECSBUS,
    COLLAUDO_NTC,
    COLLAUDO_ANALOGICHE,
    COLLAUDO_RTC_VBAT,
    COLLAUDO_I2C_EEPROM,
    COLLAUDO_SET_DATE_FROM_NTP_ETH,
    COLLAUDO_WRITE_MAC,
    COLLAUDO_WRITE_CLOUD,
    COLLAUDO_USB,
    COLLAUDO_FLASH_QSPI_PRG,
    COLLAUDO_FLASH_QSPI_DEL,
    COLLAUDO_FLASH_SPI_WBIN,
    COLLAUDO_FLASH_SPI_DEL,
    COLLAUDO_FINALIZE,
/* SPY */
    COLLAUDO_END_TESTS
};

typedef struct {
    QString test_name;
    bool    *test_en_var;
    QStringList *test_params;
} test_t;

//static test_t m_test[COLLAUDO_END_TESTS];

class CSVFileWriter: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString pippo WRITE generateFile)
    Q_PROPERTY(QString pluto WRITE openFile)

    /* COLLAUDO_START */
    Q_PROPERTY(QString startData READ getStartData WRITE setStartData)
    /* COLLAUDO_FLASH_SPI_RID */
    Q_PROPERTY(bool enabledReadSpiID MEMBER m_enabledReadSpiID)
    Q_PROPERTY(QString codeSpiID  READ getCodeSpiID  WRITE setCodeSpiID NOTIFY codeSpiIDChanged)
    /* COLLAUDO_FLASH_SPI_RW */
    Q_PROPERTY(bool enabledSpiRW MEMBER m_enabledSpiRW)
    /* COLLAUDO_FLASH_QSPI_RID */
    Q_PROPERTY(bool enabledReadQSpiID MEMBER m_enabledReadQSpiID)
    Q_PROPERTY(QString codeQSpiID  READ getCodeQSpiID  WRITE setCodeQSpiID  NOTIFY codeQSpiIDChanged)
    /* COLLAUDO_FLASH_QSPI_RW */
    Q_PROPERTY(bool enabledQSpiRW MEMBER m_enabledQSpiRW)
    /* COLLAUDO_DISPLAY_TOUCH */
    Q_PROPERTY(bool enabledDisplay MEMBER m_enabledDisplay)
    /* COLLAUDO_BACKLIGHT */
    Q_PROPERTY(bool enabledBacklight MEMBER m_enabledBacklight)
    /* COLLAUDO_BUZZER_ESTERNO */
    Q_PROPERTY(bool enabledBuzzEst MEMBER m_enabledBuzzEst)
    /* COLLAUDO_BUZZER_INTERNO */
    Q_PROPERTY(bool enabledBuzzInt MEMBER m_enabledBuzzInt)
    /* COLLAUDO_ENCODER */
    Q_PROPERTY(bool enabledEncoder MEMBER m_enabledEncoder)
    /* COLLAUDO_DIP_SWITCH */
    Q_PROPERTY(bool enabledDipSwitch MEMBER m_enabledDipSwitch)
    Q_PROPERTY(QString maskDipSwitch  READ getMaskDipSwitch  WRITE setMaskDipSwitch  NOTIFY maskDipSwitchChanged)
    /* COLLAUDO_CPU */
    Q_PROPERTY(bool enabledCpu MEMBER m_enabledCpu)
    Q_PROPERTY(QString maskCpu  READ getMaskCpu  WRITE setMaskCpu  NOTIFY maskCpuChanged)
    /* COLLAUDO_FLASH */
    Q_PROPERTY(bool enabledFlash MEMBER m_enabledFlash)
    Q_PROPERTY(QString maskFlash READ getMaskFlash WRITE setMaskFlash NOTIFY maskFlashChanged)
    /* COLLAUDO_SD */
    Q_PROPERTY(bool enabledSD MEMBER m_enabledSD)
    /* COLLAUDO_ETHERNET */
    Q_PROPERTY(bool enabledETH MEMBER m_enabledETH)
    /* COLLAUDO_WIFI */
    Q_PROPERTY(bool enabledWifi MEMBER m_enabledWifi)
    Q_PROPERTY(QString wifiData READ getWifiData WRITE setWifiData  NOTIFY wifiDataChanged)
    /* COLLAUDO_MODBUS */
    Q_PROPERTY(bool enabledModBus MEMBER m_enabledModBus)
    /* COLLAUDO_MODBUS2 */
    Q_PROPERTY(bool enabledModBus2 MEMBER m_enabledModBus2)
    /* COLLAUDO_CAN */
    Q_PROPERTY(bool enabledCanBus MEMBER m_enabledCanBus)
    /* COLLAUDO_ECSBUS */
    Q_PROPERTY(bool enabledEcsBus MEMBER m_enabledEcsBus)
    /* COLLAUDO_NTC */
    Q_PROPERTY(bool enabledNtc MEMBER m_enabledNtc)
    /* COLLAUDO_ANALOGICHE */
    Q_PROPERTY(bool enabledAnalog MEMBER m_enabledAnalog)
    /* COLLAUDO_RTC_VBAT */
    Q_PROPERTY(bool enabledRtcVbat MEMBER m_enabledRtcVbat)
    Q_PROPERTY(QString rtcVerData READ getRtcVerData WRITE setRtcVerData NOTIFY rtcVerDataChanged)
    /* COLLAUDO_I2C_EEPROM */
    Q_PROPERTY(bool enabledI2CEE MEMBER m_enabledI2CEE)
    /* COLLAUDO_SET_DATE_FROM_NTP_ETH */
    Q_PROPERTY(bool enabledEthNtp MEMBER m_enabledEthNtp)
    /* COLLAUDO_WRITE_MAC */
    Q_PROPERTY(bool enabledEthMac MEMBER m_enabledEthMac)
    /* COLLAUDO_WRITE_CLOUD */
    Q_PROPERTY(bool enabledCloud MEMBER m_enabledCloud)
    Q_PROPERTY(QString cloudData READ getCloudData WRITE setCloudData NOTIFY cloudDataChanged)
    /* COLLAUDO_USB */
    Q_PROPERTY(bool enabledUsb MEMBER m_enabledUsb)
    /* COLLAUDO_FLASH_QSPI_PRG */
    /* COLLAUDO_FLASH_QSPI_DEL */
    /* COLLAUDO_FLASH_SPI_WBIN */
    /* COLLAUDO_FLASH_SPI_DEL */
    /* COLLAUDO_FINALIZE */
    Q_PROPERTY(bool enabledFinalize MEMBER m_enabledFinalize)

private:
    QString parseTestParams(quint16 index, const bool commaFill = false);

public:
    CSVFileWriter(QObject *parent = nullptr);
    void generateFile(const QString &outpath);
    void openFile(const QString &outpath);
    void setStartData(const QString &value);
    QString getStartData();
    void setCodeSpiID(const QString &value);
    QString getCodeSpiID();
    void setEnabledReadQSpiID(const bool value);
    QString getCodeQSpiID();
    void setCodeQSpiID(const QString &value);
    QString getMaskDipSwitch();
    void setMaskDipSwitch(const QString &value);
    QString getMaskCpu();
    void setMaskCpu(const QString &value);
    QString getMaskFlash();
    void setMaskFlash(const QString &value);
    QString getWifiData();
    void setWifiData(const QString &value);        
    QString getRtcVerData();
    void setRtcVerData(const QString &value);
    QString getCloudData();
    void setCloudData(const QString &value);



signals:
    void startDataChanged(QString value);

    void enabledReadSpiIDChanged(bool value);
    void codeSpiIDChanged(QString value);
    void enabledSpiRWChanged(bool value);
    void enabledReadQSpiIDChanged(bool value);
    void codeQSpiIDChanged(QString value);
    void enabledQSpiRWChanged(bool value);
    void enabledDisplayChanged(bool value);
    void enabledBacklightChanged(bool value);
    void enabledBuzzEstChanged(bool value);
    void enabledBuzzIntChanged(bool value);
    void enabledEncoderChanged(bool value);
    void enabledDipSwitchChanged(bool value);
    void maskDipSwitchChanged(QString value);
    void enabledCpuChanged(bool value);
    void maskCpuChanged(QString value);
    void enabledFlashChanged(bool value);
    void maskFlashChanged(QString value);
    void enabledSDChanged(bool value);
    void enabledETHChanged(bool value);
    void enabledWifiChanged(bool value);
    void wifiDataChanged(QString value);
    void enabledModBusChanged(bool value);
    void enabledModBus2Changed(bool value);
    void enabledCanBusChanged(bool value);
    void enabledEcsBusChanged(bool value);
    void enabledNtcChanged(bool value);
    void enabledAnalogChanged(bool value);
    void enabledRtcVbatChanged(bool value);
    void rtcVerDataChanged(QString value);
    void enabledI2CEEChanged(bool value);
    void enabledEthNtpChanged(bool value);
    void enabledEthMacChanged(bool value);
    void enabledCloudChanged(bool value);
    void cloudDataChanged(QString value);
    void enabledUsbChanged(bool value);
    void enabledFinalizeChanged(bool value);

private:
    test_t m_test[COLLAUDO_END_TESTS];

    bool m_enabledStart;
    bool m_enabledReadSpiID;
    bool m_enabledSpiRW;
    bool m_enabledReadQSpiID;
    bool m_enabledQSpiRW;
    bool m_enabledDisplay;
    bool m_enabledBacklight;
    bool m_enabledBuzzEst;
    bool m_enabledBuzzInt;
    bool m_enabledEncoder;
    bool m_enabledDipSwitch;
    bool m_enabledCpu;
    bool m_enabledFlash;
    bool m_enabledSD;
    bool m_enabledETH;
    bool m_enabledWifi;
    bool m_enabledModBus;
    bool m_enabledModBus2;
    bool m_enabledCanBus;
    bool m_enabledEcsBus;
    bool m_enabledNtc;
    bool m_enabledAnalog;
    bool m_enabledRtcVbat;
    bool m_enabledI2CEE;
    bool m_enabledEthNtp;
    bool m_enabledEthMac;
    bool m_enabledCloud;
    bool m_enabledUsb;
    bool m_enabledFinalize;

    QString m_startData[2];
    QString m_codeSpiID[5];
    QString m_codeQSpiID[5];
    QString m_maskDipSwitch[4];
    QString m_maskCpu[5];
    QString m_maskFlash[5];
    QString m_wifiData[3];
    QString m_rtcVerData[2];
    QString m_cloudData[1];
};

#endif // CSVFILEWRITER_H
