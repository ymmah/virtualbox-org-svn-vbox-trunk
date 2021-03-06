/* $Id$ */
/** @file
 * VBox Qt GUI - UIGlobalSettingsProxy class implementation.
 */

/*
 * Copyright (C) 2011-2017 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */

#ifdef VBOX_WITH_PRECOMPILED_HEADERS
# include <precomp.h>
#else  /* !VBOX_WITH_PRECOMPILED_HEADERS */

/* Qt includes: */
# include <QRegExpValidator>

/* GUI includes: */
# include "QIWidgetValidator.h"
# include "UIGlobalSettingsProxy.h"
# include "VBoxUtils.h"

#endif /* !VBOX_WITH_PRECOMPILED_HEADERS */


UIGlobalSettingsProxy::UIGlobalSettingsProxy()
{
    /* Apply UI decorations: */
    Ui::UIGlobalSettingsProxy::setupUi(this);

    /* Setup widgets: */
    QButtonGroup *pButtonGroup = new QButtonGroup(this);
    pButtonGroup->addButton(m_pRadioProxyAuto);
    pButtonGroup->addButton(m_pRadioProxyDisabled);
    pButtonGroup->addButton(m_pRadioProxyEnabled);
    m_pPortEditor->setFixedWidthByText(QString().fill('0', 6));
    m_pHostEditor->setValidator(new QRegExpValidator(QRegExp("\\S+"), m_pHostEditor));
    m_pPortEditor->setValidator(new QRegExpValidator(QRegExp("\\d+"), m_pPortEditor));

    /* Setup connections: */
    connect(pButtonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(sltProxyToggled()));
    connect(m_pHostEditor, SIGNAL(textEdited(const QString&)), this, SLOT(revalidate()));
    connect(m_pPortEditor, SIGNAL(textEdited(const QString&)), this, SLOT(revalidate()));

    /* Apply language settings: */
    retranslateUi();
}

void UIGlobalSettingsProxy::loadToCacheFrom(QVariant &data)
{
    /* Fetch data to properties & settings: */
    UISettingsPageGlobal::fetchData(data);

    /* Clear cache initially: */
    m_cache.clear();

    /* Prepare old data: */
    UIDataSettingsGlobalProxy oldData;

    /* Gather old data: */
    UIProxyManager proxyManager(m_settings.proxySettings());
    oldData.m_enmProxyState = proxyManager.proxyState();
    oldData.m_strProxyHost = proxyManager.proxyHost();
    oldData.m_strProxyPort = proxyManager.proxyPort();

    /* Cache old data: */
    m_cache.cacheInitialData(oldData);

    /* Upload properties & settings to data: */
    UISettingsPageGlobal::uploadData(data);
}

void UIGlobalSettingsProxy::getFromCache()
{
    /* Get old data from cache: */
    const UIDataSettingsGlobalProxy &oldData = m_cache.base();

    /* Load old data from cache: */
    switch (oldData.m_enmProxyState)
    {
        case UIProxyManager::ProxyState_Auto:     m_pRadioProxyAuto->setChecked(true); break;
        case UIProxyManager::ProxyState_Disabled: m_pRadioProxyDisabled->setChecked(true); break;
        case UIProxyManager::ProxyState_Enabled:  m_pRadioProxyEnabled->setChecked(true); break;
    }
    m_pHostEditor->setText(oldData.m_strProxyHost);
    m_pPortEditor->setText(oldData.m_strProxyPort);
    sltProxyToggled();

    /* Revalidate: */
    revalidate();
}

void UIGlobalSettingsProxy::putToCache()
{
    /* Prepare new data: */
    UIDataSettingsGlobalProxy newData = m_cache.base();

    /* Gather new data: */
    newData.m_enmProxyState = m_pRadioProxyEnabled->isChecked()  ? UIProxyManager::ProxyState_Enabled :
                              m_pRadioProxyDisabled->isChecked() ? UIProxyManager::ProxyState_Disabled :
                                                                   UIProxyManager::ProxyState_Auto;
    newData.m_strProxyHost = m_pHostEditor->text();
    newData.m_strProxyPort = m_pPortEditor->text();

    /* Cache new data: */
    m_cache.cacheCurrentData(newData);
}

void UIGlobalSettingsProxy::saveFromCacheTo(QVariant &data)
{
    /* Fetch data to properties & settings: */
    UISettingsPageGlobal::fetchData(data);

    /* Save new data from cache: */
    if (m_cache.wasChanged())
    {
        UIProxyManager proxyManager;
        proxyManager.setProxyState(m_cache.data().m_enmProxyState);
        proxyManager.setProxyHost(m_cache.data().m_strProxyHost);
        proxyManager.setProxyPort(m_cache.data().m_strProxyPort);
        m_settings.setProxySettings(proxyManager.toString());
    }

    /* Upload properties & settings to data: */
    UISettingsPageGlobal::uploadData(data);
}

bool UIGlobalSettingsProxy::validate(QList<UIValidationMessage> &messages)
{
    /* Pass if proxy is disabled: */
    if (!m_pRadioProxyEnabled->isChecked())
        return true;

    /* Pass by default: */
    bool fPass = true;

    /* Prepare message: */
    UIValidationMessage message;

    /* Check for host value: */
    if (m_pHostEditor->text().trimmed().isEmpty())
    {
        message.second << tr("No proxy host is currently specified.");
        fPass = false;
    }

    /* Check for port value: */
    if (m_pPortEditor->text().trimmed().isEmpty())
    {
        message.second << tr("No proxy port is currently specified.");
        fPass = false;
    }

    /* Serialize message: */
    if (!message.second.isEmpty())
        messages << message;

    /* Return result: */
    return fPass;
}

void UIGlobalSettingsProxy::setOrderAfter(QWidget *pWidget)
{
    /* Configure navigation: */
    setTabOrder(pWidget, m_pRadioProxyAuto);
    setTabOrder(m_pRadioProxyAuto, m_pRadioProxyDisabled);
    setTabOrder(m_pRadioProxyDisabled, m_pRadioProxyEnabled);
    setTabOrder(m_pRadioProxyEnabled, m_pHostEditor);
    setTabOrder(m_pHostEditor, m_pPortEditor);
}

void UIGlobalSettingsProxy::retranslateUi()
{
    /* Translate uic generated strings: */
    Ui::UIGlobalSettingsProxy::retranslateUi(this);
}

void UIGlobalSettingsProxy::sltProxyToggled()
{
    /* Update widgets availability: */
    m_pContainerProxy->setEnabled(m_pRadioProxyEnabled->isChecked());

    /* Revalidate: */
    revalidate();
}

