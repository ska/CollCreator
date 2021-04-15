import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Dialogs 1.2
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
//import Qt.labs.platform 1.1
import ls.sierra_kilo_alpha.CsvWriter 1.0

Window {
    id: mainwin
    visible: true
    width: 1200
    height: 930

    title: qsTr("Alpha5 CSV Creator")
    color: "#aaaaaa"

    CSVFileWriter {
        id: csv
        onEnabledReadSpiIDChanged:  checkBoxSpiRID.checked = value
        onEnabledSpiRWChanged:      checkBoxCollFlashSpiRW.checked = value
        onEnabledReadQSpiIDChanged: checkBoxQSpiRID.checked = value
        onEnabledQSpiRWChanged:     checkBoxCollFlashQSpiRW.checked = value
        onEnabledDisplayChanged:    checkBoxCollDisplayTouch.checked = value
        onEnabledBacklightChanged:  checkBoxCollBacklight.checked = value
        onEnabledBuzzEstChanged:    checkBoxCollBuzzerEsterno.checked = value
        onEnabledBuzzIntChanged:    checkBoxCollBuzzerInterno.checked = value
        onEnabledEncoderChanged:    checkBoxCollEncoder.checked = value
        onEnabledDipSwitchChanged:  checkBoxDipSwitch.checked = value
        onEnabledCpuChanged:        checkBoxCPU.checked = value
        onEnabledFlashChanged:      checkBoxFlash.checked = value
        onEnabledSDChanged:         checkBoxCollSD.checked = value
        onEnabledETHChanged:        checkBoxCollEthernet.checked = value
        onEnabledWifiChanged:       checkBoxWifi.checked = value
        onEnabledModBusChanged:     checkBoxCollModbus.checked = value
        onEnabledModBus2Changed:    checkBoxCollModbus2.checked = value
        onEnabledCanBusChanged:     checkBoxCollCan.checked = value
        onEnabledEcsBusChanged:     checkBoxCollECSBus.checked = value
        onEnabledNtcChanged:        checkBoxCollNtc.checked = value
        onEnabledAnalogChanged:     checkBoxCollAnalogiche.checked = value
        onEnabledRtcVbatChanged:    checkBoxRtcVbat.checked = value
        onEnabledI2CEEChanged:      checkBoxCollI2CEEprom.checked = value
        onEnabledEthNtpChanged:     checkBoxCollNtpEth.checked = value
        onEnabledEthMacChanged:     checkBoxCollWriteMac.checked = value
        onEnabledUsbChanged:        checkBoxCollUsb.checked = value
        onEnabledFinalizeChanged:   checkBoxFinalize.checked = value
        onStartDataChanged: {
            console.log( value);
            var res = value.split(",");
            if(res[0])
                textCustomer.text = res[0].trim()
            if(res[1])
                textCode.text = res[1].trim()
        }
        onCodeSpiIDChanged: {
            console.log("codeSpiIDChanged changed: ", value)
            var res = value.split(",");
            if(res[0])
                textSPIFlashId0.text = res[0].trim()
            if(res[1])
                textSPIFlashId1.text = res[1].trim()
            if(res[2])
                textSPIFlashId2.text = res[2].trim()
            if(res[3])
                textSPIFlashId3.text = res[3].trim()
            if(res[4])
                textSPIFlashId4.text = res[4].trim()
        }
        onCodeQSpiIDChanged: {
            console.log("onCodeQSpiIDChanged changed: ", value)
            var res = value.split(",");
            if(res[0])
                textQSPIFlashId0.text = res[0].trim()
            if(res[1])
                textQSPIFlashId1.text = res[1].trim()
            if(res[2])
                textQSPIFlashId2.text = res[2].trim()
            if(res[3])
                textQSPIFlashId3.text = res[3].trim()
            if(res[4])
                textQSPIFlashId4.text = res[4].trim()
        }
        onMaskDipSwitchChanged: {
            console.log("onMaskDipSwitchChanged changed: ", value)
            var res = value.split(",");
            if(res[0])
                checkBoxDipSwitchEn0.checked = (res[0].trim() == '1' ? true : false)
            if(res[1])
                checkBoxDipSwitchEn1.checked = (res[1].trim() == '1' ? true : false)
            if(res[2])
                checkBoxDipSwitchEn2.checked = (res[2].trim() == '1' ? true : false)
            if(res[3])
                checkBoxDipSwitchEn3.checked = (res[3].trim() == '1' ? true : false)
        }
        onMaskCpuChanged: {
            console.log("onMaskCpuChanged changed: ", value)
            var res = value.split(",");
            if(res[0])
                textCPUId0.text = res[0].trim()
            if(res[1])
                textCPUId1.text = res[1].trim()
            if(res[2])
                textCPUId2.text = res[2].trim()
            if(res[3])
                textCPUId3.text = res[3].trim()
            if(res[4])
                textCPUId4.text = res[4].trim()
        }
        onMaskFlashChanged: {
            console.log("onMaskFlashChanged changed: ", value)
            var res = value.split(",");
            if(res[0])
                textFlashSz0.text = res[0].trim()
            if(res[1])
                textFlashSz1.text = res[1].trim()
            if(res[2])
                textFlashSz2.text = res[2].trim()
            if(res[3])
                textFlashSz3.text = res[3].trim()
            if(res[4])
                textFlashSz4.text = res[4].trim()
        }
        onRtcVerDataChanged: {
            console.log("onRtcVerDataChanged changed: ", value)
            var res = value.split(",");
            if(res[0])
                textRtcVer.text = res[0].trim()
            if(res[1])
                textRtcVerOffset.text = res[1].trim()
        }
        onWifiDataChanged: {
            console.log("onMaskFlashChanged changed: ", value)
            var res = value.split(",");
            if(res[0])
                textSSID.text = res[0].trim()
            if(res[1])
                textPSK.text = res[1].trim()
            //if(res[2])
            //    textFlashSz2.text = res[2].trim()
        }
        onCloudDataChanged: {
            console.log("onCloudDataChanged changed: ", value)
            var res = value.split(",");
            if(res[0])
                textCollWriteCloud.text = res[0].trim()
        }

    }

    Rectangle {
        id: rectCollStart
        x: 15
        y: 15
        width: 280
        height: 131
        color: "#ffffff"
        radius: 3
        border.color: "#735dfc"
        border.width: 2

        CheckBox {
            id: checkBoxStart
            checked: true
            enabled: false
            x: 8
            y: 8
            width: 262
            height: 32
            text: qsTr("COLLAUDO_START")
            font.bold: true
        }

        Label {
            id: labelCustomer
            x: 8
            y: 52
            width: 132
            height: 26
            text: qsTr("CUSTOMER NAME")
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.pointSize: 9
        }

        TextField {
            id: textCustomer
            x: 150
            y: 52
            width: 120
            height: 26
            font.pixelSize: 14
            font.family: "Helvetica"
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            placeholderText: "ACME tnt"
            validator: RegExpValidator { regExp: /[\w@$!£.-_& ]{0,24}/ }
            onTextChanged: csv.startData = "0:" + this.text
        }

        Label {
            id: labelCode
            x: 8
            y: 90
            width: 132
            height: 26
            text: qsTr("P00_ECS_CODE")
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.pointSize: 9
        }

        TextField {
            id: textCode
            x: 150
            y: 90
            width: 120
            height: 26
            font.pixelSize: 14
            font.family: "Helvetica"
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            placeholderText: "P00xxxxx-x"
            validator: RegExpValidator { regExp: /P[0-9]{7}-[\w]{1}/ }
            onTextChanged: csv.startData = "1:" + this.text
        }
    }

    Rectangle {
        id: rectCollSpiRID
        x: 15
        y: 478
        width: 280
        height: 214
        color: "#ffffff"
        radius: 3
        border.color: "#735dfc"
        border.width: 2

        CheckBox {
            id: checkBoxSpiRID
            x: 8
            y: 8
            width: 264
            height: 32
            text: qsTr("COLLAUDO_FLASH_SPI_RID")
            font.bold: true
            checked: false
            enabled: true
            onCheckedChanged: csv.enabledReadSpiID = this.checked
        }

        Label {
            id: labelSPIFlashId0
            x: 8
            y: 52
            width: 132
            height: 26
            text: qsTr("FLASH_ID_0")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textSPIFlashId0
            x: 150
            y: 52
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x00000000"
            validator: RegExpValidator { regExp: /0x[0-9A-Fa-f]{8}/ }
            onTextChanged: {
                console.log("onTextChanged 0:" + this.text)
                csv.codeSpiID = "0:" + this.text
            }
        }

        Label {
            id: labelSPIFlashId1
            x: 8
            y: 84
            width: 132
            height: 26
            text: qsTr("FLASH_ID_1")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textSPIFlashId1
            x: 150
            y: 84
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x00000000"
            validator: RegExpValidator { regExp: /0x[0-9A-Fa-f]{8}/ }
            onTextChanged: {
                console.log("onTextChanged 1:" + this.text)
                csv.codeSpiID = "1:" + this.text
            }
        }

        Label {
            id: labelSPIFlashId2
            x: 8
            y: 116
            width: 132
            height: 26
            text: qsTr("FLASH_ID_2")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textSPIFlashId2
            x: 150
            y: 116
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x00000000"
            validator: RegExpValidator { regExp: /0x[0-9A-Fa-f]{8}/ }
            onTextChanged: {
                console.log("onTextChanged 2:" + this.text)
                csv.codeSpiID = "2:" + this.text
            }
        }

        Label {
            id: labelSPIFlashId3
            x: 8
            y: 148
            width: 132
            height: 26
            text: qsTr("FLASH_ID_3")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textSPIFlashId3
            x: 150
            y: 148
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x00000000"
            validator: RegExpValidator { regExp: /0x[0-9A-Fa-f]{8}/ }
            onTextChanged: {
                console.log("onTextChanged 3:" + this.text)
                csv.codeSpiID = "3:" + this.text
            }
        }

        Label {
            id: labelSPIFlashId4
            x: 8
            y: 180
            width: 132
            height: 26
            text: qsTr("FLASH_ID_0")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textSPIFlashId4
            x: 150
            y: 180
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x00000000"
            validator: RegExpValidator { regExp: /0x[0-9A-Fa-f]{8}/ }
            onTextChanged: {
                console.log("onTextChanged 4:" + this.text)
                csv.codeSpiID = "4:" + this.text
            }
        }
    }

    Rectangle {
        id: rectCollQSpiRID
        x: 15
        y: 698
        width: 280
        height: 214
        color: "#ffffff"
        radius: 3
        border.color: "#735dfc"
        border.width: 2
        CheckBox {
            id: checkBoxQSpiRID
            x: 8
            y: 8
            width: 264
            height: 32
            text: qsTr("COLLAUDO_FLASH_QSPI_RID")
            font.bold: true
            checked: false
            enabled: true
            onCheckedChanged: {
                console.log("onCheckedChanged")
                csv.enabledReadQSpiID = this.checked
            }
        }

        Label {
            id: labelQSPIFlashId0
            x: 8
            y: 52
            width: 132
            height: 26
            text: qsTr("FLASH_ID_0")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textQSPIFlashId0
            x: 150
            y: 52
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x00000000"
            validator: RegExpValidator { regExp: /0x[0-9A-Fa-f]{8}/ }
            onTextChanged: {
                console.log("onTextChanged 0:" + this.text)
                csv.codeQSpiID = "0:" + this.text
            }
        }

        Label {
            id: labelQSPIFlashId1
            x: 8
            y: 84
            width: 132
            height: 26
            text: qsTr("FLASH_ID_1")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textQSPIFlashId1
            x: 150
            y: 84
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x00000000"
            validator: RegExpValidator { regExp: /0x[0-9A-Fa-f]{8}/ }
            onTextChanged: {
                console.log("onTextChanged 1:" + this.text)
                csv.codeQSpiID = "1:" + this.text
            }
        }

        Label {
            id: labelQSPIFlashId2
            x: 8
            y: 116
            width: 132
            height: 26
            text: qsTr("FLASH_ID_2")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textQSPIFlashId2
            x: 150
            y: 116
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x00000000"
            validator: RegExpValidator { regExp: /0x[0-9A-Fa-f]{8}/ }
            onTextChanged: {
                console.log("onTextChanged 2:" + this.text)
                csv.codeQSpiID = "2:" + this.text
            }
        }

        Label {
            id: labelQSPIFlashId3
            x: 8
            y: 148
            width: 132
            height: 26
            text: qsTr("FLASH_ID_3")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textQSPIFlashId3
            x: 150
            y: 148
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x00000000"
            validator: RegExpValidator { regExp: /0x[0-9A-Fa-f]{8}/ }
            onTextChanged: {
                console.log("onTextChanged 3:" + this.text)
                csv.codeQSpiID = "3:" + this.text
            }
        }

        Label {
            id: labelQSPIFlashId4
            x: 8
            y: 180
            width: 132
            height: 26
            text: qsTr("FLASH_ID_0")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textQSPIFlashId4
            x: 150
            y: 180
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x00000000"
            validator: RegExpValidator { regExp: /0x[0-9A-Fa-f]{8}/ }
            onTextChanged: {
                console.log("onTextChanged 4:" + this.text)
                csv.codeQSpiID = "4:" + this.text
            }
        }
    }

    Rectangle {
        id: rectCollDipSwitch
        x: 615
        y: 478
        width: 280
        height: 214
        color: "#ffffff"
        radius: 3
        border.color: "#735dfc"
        border.width: 2
        CheckBox {
            id: checkBoxDipSwitch
            x: 8
            y: 8
            width: 264
            height: 32
            text: qsTr("COLLAUDO_DIP_SWITCH")
            font.bold: true
            checked: false
            enabled: true
            onCheckedChanged: csv.enabledDipSwitch = this.checked
        }

        CheckBox {
            id: checkBoxDipSwitchEn0
            x: 8
            y: 52
            width: 264
            height: 32
            text: qsTr("DIP_1_TEST_EN")
            checked: false
            enabled: true
            onCheckedChanged: {
                console.log("onCheckedChanged DIP_1_TEST_EN 0:"+Number(this.checked))
                csv.maskDipSwitch = "0:" +Number(this.checked)
            }
        }

        CheckBox {
            id: checkBoxDipSwitchEn1
            x: 8
            y: 91
            width: 264
            height: 32
            text: qsTr("DIP_2_TEST_EN")
            checked: false
            enabled: true
            onCheckedChanged: {
                console.log("onCheckedChanged DIP_2_TEST_EN 1:"+Number(this.checked))
                csv.maskDipSwitch = "1:" +Number(this.checked)
            }
        }

        CheckBox {
            id: checkBoxDipSwitchEn2
            x: 8
            y: 132
            width: 264
            height: 32
            text: qsTr("DIP_3_TEST_EN")
            checked: false
            enabled: true
            onCheckedChanged: {
                console.log("onCheckedChanged DIP_3_TEST_EN 2:"+Number(this.checked))
                csv.maskDipSwitch = "2:" +Number(this.checked)
            }
        }

        CheckBox {
            id: checkBoxDipSwitchEn3
            x: 8
            y: 174
            width: 264
            height: 32
            text: qsTr("DIP_4_TEST_EN")
            checked: false
            enabled: true
            onCheckedChanged: {
                console.log("onCheckedChanged DIP_4_TEST_EN 3:"+Number(this.checked))
                csv.maskDipSwitch = "3:" +Number(this.checked)
            }
        }
    }

    Rectangle {
        id: rectCollCPU
        x: 312
        y: 478
        width: 280
        height: 214
        color: "#ffffff"
        radius: 3
        border.color: "#735dfc"
        border.width: 2
        CheckBox {
            id: checkBoxCPU
            x: 8
            y: 8
            width: 264
            height: 32
            text: qsTr("COLLAUDO_CPU")
            font.bold: true
            checked: false
            enabled: true
            onCheckedChanged: csv.enabledCpu = this.checked
        }

        Label {
            id: labelCPUId0
            x: 8
            y: 52
            width: 132
            height: 26
            text: qsTr("CPU_ID_REV_0")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textCPUId0
            x: 150
            y: 52
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x00000000"
            validator: RegExpValidator {
                regExp: /0x[0-9A-Fa-f]{8}/
            }
            onTextChanged: {
                console.log("textCPUId0 0:" + this.text)
                csv.maskCpu = "0:" + this.text
            }
        }

        Label {
            id: labelCPUId1
            x: 8
            y: 84
            width: 132
            height: 26
            text: qsTr("CPU_ID_REV_1")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textCPUId1
            x: 150
            y: 84
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x00000000"
            validator: RegExpValidator {
                regExp: /0x[0-9A-Fa-f]{8}/
            }
            onTextChanged: {
                console.log("textCPUId1 1:" + this.text)
                csv.maskCpu = "1:" + this.text
            }
        }

        Label {
            id: labelCPUId2
            x: 8
            y: 116
            width: 132
            height: 26
            text: qsTr("CPU_ID_REV_2")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textCPUId2
            x: 150
            y: 116
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x00000000"
            validator: RegExpValidator {
                regExp: /0x[0-9A-Fa-f]{8}/
            }
            onTextChanged: {
                console.log("textCPUId2 2:" + this.text)
                csv.maskCpu = "2:" + this.text
            }
        }

        Label {
            id: labelCPUId3
            x: 8
            y: 148
            width: 132
            height: 26
            text: qsTr("CPU_ID_REV_3")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textCPUId3
            x: 150
            y: 148
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x00000000"
            validator: RegExpValidator {
                regExp: /0x[0-9A-Fa-f]{8}/
            }
            onTextChanged: {
                console.log("textCPUId3 3:" + this.text)
                csv.maskCpu = "3:" + this.text
            }
        }

        Label {
            id: labelCPUId4
            x: 8
            y: 180
            width: 132
            height: 26
            text: qsTr("CPU_ID_REV_4")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textCPUId4
            x: 150
            y: 180
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x00000000"
            validator: RegExpValidator {
                regExp: /0x[0-9A-Fa-f]{8}/
            }
            onTextChanged: {
                console.log("textCPUId4 4:" + this.text)
                csv.maskCpu = "4:" + this.text
            }
        }
    }

    Rectangle {
        id: rectCollFlashSize
        x: 312
        y: 698
        width: 280
        height: 214
        color: "#ffffff"
        radius: 3
        border.color: "#735dfc"
        border.width: 2
        CheckBox {
            id: checkBoxFlash
            x: 8
            y: 8
            width: 264
            height: 32
            text: qsTr("COLLAUDO_FLASH")
            font.bold: true
            checked: false
            enabled: true
            onCheckedChanged: csv.enabledFlash = this.checked
        }

        Label {
            id: labelFlashSz0
            x: 8
            y: 52
            width: 132
            height: 26
            text: qsTr("CPU_FLASH_SZ_0")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textFlashSz0
            x: 150
            y: 52
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0000 KB"
            validator: RegExpValidator {
                regExp: /[0-9]{1,5}/
            }
            onTextChanged: {
                console.log("textFlashSz0 0:" + this.text)
                csv.maskFlash = "0:" + this.text
            }
        }

        Label {
            id: labelFlashSz1
            x: 8
            y: 84
            width: 132
            height: 26
            text: qsTr("CPU_FLASH_SZ_1")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textFlashSz1
            x: 150
            y: 84
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0000 KB"
            validator: RegExpValidator {
                regExp: /[0-9]{1,5}/
            }
            onTextChanged: {
                console.log("textFlashSz1 1:" + this.text)
                csv.maskFlash = "1:" + this.text
            }
        }

        Label {
            id: labelFlashSz2
            x: 8
            y: 116
            width: 132
            height: 26
            text: qsTr("CPU_FLASH_SZ_2")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textFlashSz2
            x: 150
            y: 116
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0000 KB"
            validator: RegExpValidator {
                regExp: /[0-9]{1,5}/
            }
            onTextChanged: {
                console.log("textFlashSz2 2:" + this.text)
                csv.maskFlash = "2:" + this.text
            }
        }

        Label {
            id: labelFlashSz3
            x: 8
            y: 148
            width: 132
            height: 26
            text: qsTr("CPU_FLASH_SZ_3")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textFlashSz3
            x: 150
            y: 148
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0000 KB"
            validator: RegExpValidator {
                regExp: /[0-9]{1,5}/
            }
            onTextChanged: {
                console.log("textFlashSz3 3:" + this.text)
                csv.maskFlash = "3:" + this.text
            }
        }

        Label {
            id: labelFlashSz4
            x: 8
            y: 180
            width: 132
            height: 26
            text: qsTr("CPU_FLASH_SZ_4")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textFlashSz4
            x: 150
            y: 180
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0000 KB"
            validator: RegExpValidator {
                regExp: /[0-9]{1,5}/
            }
            onTextChanged: {
                console.log("textFlashSz4 4:" + this.text)
                csv.maskFlash = "4:" + this.text
            }
        }
    }

    Rectangle {
        id: rectCollWifi
        x: 15
        y: 157
        width: 280
        height: 177
        color: "#ffffff"
        radius: 3
        border.color: "#735dfc"
        border.width: 2
        CheckBox {
            id: checkBoxWifi
            x: 8
            y: 8
            width: 262
            height: 32
            text: qsTr("COLLAUDO_WIFI")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledWifi = this.checked
        }

        Label {
            id: labelSSID
            x: 8
            y: 52
            width: 132
            height: 26
            text: qsTr("SSID")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textSSID
            x: 100
            y: 52
            width: 170
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "Net name"
            validator: RegExpValidator { regExp: /[\w\W]{0,24}/ }
            onTextChanged: csv.wifiData = "0:" + this.text;
        }

        Label {
            id: labelPSK
            x: 8
            y: 90
            width: 132
            height: 26
            text: qsTr("PSK")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textPSK
            x: 100
            y: 90
            width: 170
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "Net Psw"
            validator: RegExpValidator { regExp: /[\w\W]{0,24}/ }
            onTextChanged: csv.wifiData = "1:" + this.text;
        }

        Label {
            id: labelRssi
            x: 8
            y: 128
            width: 132
            height: 26
            text: qsTr("RSSI min")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        ComboBox {
            id: comboBoxRssi
            x: 100
            y: 129
            width: 170
            height: 26
            currentIndex: 0
            model: ListModel {
                id: arItems
                ListElement { text: "0" }
                ListElement { text: "-50" }
                ListElement { text: "-60" }
                ListElement { text: "-65" }
                ListElement { text: "-70" }
                ListElement { text: "-75" }
                ListElement { text: "-80" }
            }
            onCurrentIndexChanged: csv.wifiData = "2:" + arItems.get(currentIndex).text;
        }
    }

    Rectangle {
        id: rectCollRtcVbat
        x: 15
        y: 340
        width: 280
        height: 131
        color: "#ffffff"
        radius: 3
        border.color: "#735dfc"
        border.width: 2
        CheckBox {
            id: checkBoxRtcVbat
            x: 8
            y: 8
            width: 262
            height: 32
            text: qsTr("COLLAUDO_RTC_VBAT")
            checked: false
            font.bold: true
            enabled: true
        }

        Label {
            id: labelRtcVer
            x: 8
            y: 52
            width: 132
            height: 26
            text: qsTr("RTC_VER")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textRtcVer
            x: 150
            y: 52
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0xCAFE"
        }

        Label {
            id: labelRtcVerOffset
            x: 8
            y: 90
            width: 132
            height: 26
            text: qsTr("RTC_VER_OFFSET")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textRtcVerOffset
            x: 150
            y: 90
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x0000"
        }

    }

    Rectangle {
        id: rectCollGeneric
        x: 312
        y: 15
        width: 583
        height: 396
        color: "#ffffff"
        radius: 3
        border.color: "#735dfc"
        border.width: 2

        CheckBox {
            id: checkBoxCollFlashSpiRW
            x: 8
            y: 8
            width: 262
            height: 32
            text: qsTr("COLLAUDO_FLASH_SPI_RW")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledSpiRW = this.checked
        }

        CheckBox {
            id: checkBoxCollFlashQSpiRW
            x: 8
            y: 46
            width: 262
            height: 32
            text: qsTr("COLLAUDO_FLASH_QSPI_RW")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledQSpiRW = this.checked
        }

        CheckBox {
            id: checkBoxCollDisplayTouch
            x: 8
            y: 84
            width: 262
            height: 32
            text: qsTr("COLLAUDO_DISPLAY_TOUCH")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledDisplay = this.checked
        }

        CheckBox {
            id: checkBoxCollBacklight
            x: 8
            y: 122
            width: 262
            height: 32
            text: qsTr("COLLAUDO_BACKLIGHT")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledBacklight = this.checked
        }

        CheckBox {
            id: checkBoxCollBuzzerEsterno
            x: 8
            y: 160
            width: 262
            height: 32
            text: qsTr("COLLAUDO_BUZZER_ESTERNO")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledBuzzEst = this.checked
        }

        CheckBox {
            id: checkBoxCollBuzzerInterno
            x: 8
            y: 198
            width: 262
            height: 32
            text: qsTr("COLLAUDO_BUZZER_INTERNO")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledBuzzInt = this.checked
        }

        CheckBox {
            id: checkBoxCollEncoder
            x: 8
            y: 236
            width: 262
            height: 32
            text: qsTr("COLLAUDO_ENCODER")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledEncoder = this.checked
        }

        CheckBox {
            id: checkBoxCollSD
            x: 8
            y: 274
            width: 262
            height: 32
            text: qsTr("COLLAUDO_SD")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledSD = this.checked
        }

        CheckBox {
            id: checkBoxCollEthernet
            x: 8
            y: 312
            width: 262
            height: 32
            text: qsTr("COLLAUDO_ETHERNET")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledETH = this.checked
        }

        CheckBox {
            id: checkBoxCollModbus
            x: 307
            y: 8
            width: 262
            height: 32
            text: qsTr("COLLAUDO_MODBUS")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledModBus = this.checked
        }

        CheckBox {
            id: checkBoxCollModbus2
            x: 307
            y: 46
            width: 262
            height: 32
            text: qsTr("COLLAUDO_MODBUS2")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledModBus2 = this.checked
        }

        CheckBox {
            id: checkBoxCollCan
            x: 307
            y: 84
            width: 262
            height: 32
            text: qsTr("COLLAUDO_CAN")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledCanBus = this.checked
        }

        CheckBox {
            id: checkBoxCollECSBus
            x: 307
            y: 122
            width: 262
            height: 32
            text: qsTr("COLLAUDO_ECSBUS")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledEcsBus = this.checked
        }

        CheckBox {
            id: checkBoxCollNtc
            x: 307
            y: 160
            width: 262
            height: 32
            text: qsTr("COLLAUDO_NTC")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledNtc = this.checked
        }

        CheckBox {
            id: checkBoxCollAnalogiche
            x: 307
            y: 198
            width: 262
            height: 32
            text: qsTr("COLLAUDO_ANALOGICHE")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledAnalog = this.checked
        }

        CheckBox {
            id: checkBoxCollI2CEEprom
            x: 307
            y: 236
            width: 262
            height: 32
            text: qsTr("COLLAUDO_I2C_EEPROM")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledI2CEE = this.checked
        }

        CheckBox {
            id: checkBoxCollWriteMac
            x: 307
            y: 274
            width: 262
            height: 32
            text: qsTr("COLLAUDO_WRITE_MAC")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledEthMac = this.checked
        }

        CheckBox {
            id: checkBoxCollNtpEth
            x: 307
            y: 312
            width: 262
            height: 32
            text: qsTr("COLLAUDO_USE_NTP_ETH")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledEthNtp = this.checked
        }

        CheckBox {
            id: checkBoxCollUsb
            x: 8
            y: 350
            width: 262
            height: 32
            text: qsTr("COLLAUDO_USB")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledUsb = this.checked
        }
    }

    Rectangle {
        id: rectCollWriteCloud
        x: 314
        y: 417
        width: 581
        height: 54
        color: "#ffffff"
        radius: 3
        border.color: "#735dfc"
        border.width: 2
        CheckBox {
            id: checkCollWriteCloud
            x: 8
            y: 8
            width: 262
            height: 32
            text: qsTr("COLLAUDO_WRITE_CLOUD")
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledCloud = this.checked
        }

        Label {
            id: labelCollWriteCloud
            x: 290
            y: 11
            width: 155
            height: 26
            text: qsTr("MATRICOLA_DEFAULT")
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textCollWriteCloud
            x: 451
            y: 11
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0xCAFE"
        }

    }

    Rectangle {
        id: rectCollFinalize
        x: 908
        y: 637
        width: 280
        height: 55
        color: "#f9c36c"
        radius: 3
        border.color: "#735dfc"
        border.width: 2
        CheckBox {
            id: checkBoxFinalize
            x: 8
            y: 8
            width: 262
            height: 32
            text: "COLLAUDO_FINALIZE"
            font.pointSize: 10
            checked: false
            font.bold: true
            enabled: true
            onCheckedChanged: csv.enabledFinalize = this.checked
        }
    }




    Rectangle {
        id: rectCollFlashSpiPrg
        x: 908
        y: 15
        width: 280
        height: 160
        color: "#bde6f8"
        radius: 3
        border.color: "#735dfc"
        border.width: 2
        CheckBox {
            id: checkBoxRtcVbat2
            x: 8
            y: 8
            width: 262
            height: 32
            text: qsTr("COLLAUDO_FLASH_QSPI_PRG")
            checked: false
            font.bold: true
            enabled: true
        }

        Label {
            id: labelCustomer3
            x: 8
            y: 90
            width: 132
            height: 26
            text: qsTr("FILE_NAME")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textCustomer4
            x: 150
            y: 52
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0xCAFE"
        }

        Label {
            id: labelCustomer5
            x: 8
            y: 52
            width: 132
            height: 26
            text: qsTr("OFFSET")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        Button {
            id: button
            x: 8
            y: 122
            width: 262
            height: 26
            text: qsTr("Select..")
        }

        Label {
            id: labelCustomer7
            x: 138
            y: 90
            width: 132
            height: 26
            text: qsTr("FILE_MD5_NAME")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }
    }

    Rectangle {
        id: rectCollFlashSpiWbin
        x: 908
        y: 189
        width: 280
        height: 151
        color: "#bde6f8"
        radius: 3
        border.color: "#735dfc"
        border.width: 2
        CheckBox {
            id: checkBoxRtcVbat3
            x: 8
            y: 8
            width: 262
            height: 32
            text: qsTr("COLLAUDO_FLASH_SPI_WBIN")
            checked: false
            font.bold: true
            enabled: true
        }

        Label {
            id: labelCustomer6
            x: 8
            y: 63
            width: 132
            height: 26
            text: qsTr("FILE_NAME")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        Button {
            id: button1
            x: 8
            y: 112
            width: 262
            height: 26
            text: qsTr("Select..")
        }

        Label {
            id: labelCustomer9
            x: 138
            y: 63
            width: 132
            height: 26
            text: qsTr("FILE_MD5_NAME")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }
    }

    Rectangle {
        id: rectCollFlashQspiDel
        x: 908
        y: 353
        width: 280
        height: 131
        color: "#bde6f8"
        radius: 3
        border.color: "#735dfc"
        border.width: 2
        CheckBox {
            id: checkBoxRtcVbat4
            x: 8
            y: 8
            width: 262
            height: 32
            text: qsTr("COLLAUDO_FLASH_QSPI_DEL")
            checked: true
            font.bold: true
            enabled: true
        }

        Label {
            id: labelCustomer8
            x: 8
            y: 90
            width: 132
            height: 26
            text: qsTr("ERASE_SIZE")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textCustomer5
            x: 150
            y: 52
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0xCAFE"
        }

        TextField {
            id: textCode3
            x: 150
            y: 90
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x0000"
        }

        Label {
            id: labelCustomer10
            x: 8
            y: 52
            width: 132
            height: 26
            text: qsTr("START_OFFSET")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }
    }

    Rectangle {
        id: rectCollFlashSpiDel
        x: 908
        y: 496
        width: 280
        height: 131
        color: "#bde6f8"
        radius: 3
        border.color: "#735dfc"
        border.width: 2
        CheckBox {
            id: checkBoxRtcVbat5
            x: 8
            y: 8
            width: 262
            height: 32
            text: qsTr("COLLAUDO_FLASH_SPI_DEL")
            checked: false
            font.bold: true
            enabled: true
        }

        Label {
            id: labelCustomer11
            x: 8
            y: 90
            width: 132
            height: 26
            text: qsTr("ERASE_SIZE")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }

        TextField {
            id: textCustomer6
            x: 150
            y: 52
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0xCAFE"
        }

        TextField {
            id: textCode4
            x: 150
            y: 90
            width: 120
            height: 26
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            font.family: "Helvetica"
            font.bold: true
            placeholderText: "0x0000"
        }

        Label {
            id: labelCustomer12
            x: 8
            y: 52
            width: 132
            height: 26
            text: qsTr("START_OFFSET")
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 9
            font.family: "Helvetica"
        }
    }





    Button {
        id: button2
        x: 1020
        y: 811
        width: 117
        height: 40
        text: qsTr("Generate CSV file")
        onReleased: csv.pippo = "folder path"
    }

    Button {
        id: button3
        x: 1020
        y: 857
        width: 117
        height: 40
        text: qsTr("Open CSV file")
        //onReleased: csv.pluto = "file path"
        onClicked: fileDialog.visible = true
    }


    Item {

        FileDialog {
            id: fileDialog
            title: "Please choose a file"
            //folder: StandardPaths.writableLocation(StandardPaths.HomeLocation)
            folder: shortcuts.home
            nameFilters: [ "Test File (*.csv)", "All files (*)" ]

            onAccepted: {
                console.log("fileDialog.fileUrls: " + fileDialog.fileUrls)
                //fileLabel.text = ""+ fileDialog.fileUrls
                csv.pluto = "" + fileDialog.fileUrls
                fileDialog.visible= false
            }
            onRejected: {
                console.log("Canceled")
            }
            Component.onCompleted: visible = false
        }

    }


}


