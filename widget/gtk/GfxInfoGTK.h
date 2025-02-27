/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 * vim: sw=2 ts=8 et :
 */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __GfxInfoGTK_h__
#define __GfxInfoGTK_h__

#include "GfxInfoBase.h"

namespace mozilla {
namespace widget {

// TODO: Should wrap GfxInfoX11

class GfxInfo final : public GfxInfoBase
{
public:

  // We only declare the subset of nsIGfxInfo that we actually implement. The
  // rest is brought forward from GfxInfoBase.
  NS_IMETHOD GetD2DEnabled(bool *aD2DEnabled) override;
  NS_IMETHOD GetDWriteEnabled(bool *aDWriteEnabled) override;
  NS_IMETHOD GetDWriteVersion(nsAString & aDwriteVersion) override;
  NS_IMETHOD GetCleartypeParameters(nsAString & aCleartypeParams) override;
  NS_IMETHOD GetAdapterDescription(nsAString & aAdapterDescription) override;
  NS_IMETHOD GetAdapterDriver(nsAString & aAdapterDriver) override;
  NS_IMETHOD GetAdapterVendorID(nsAString & aAdapterVendorID) override;
  NS_IMETHOD GetAdapterDeviceID(nsAString & aAdapterDeviceID) override;
  NS_IMETHOD GetAdapterSubsysID(nsAString & aAdapterSubsysID) override;
  NS_IMETHOD GetAdapterRAM(nsAString & aAdapterRAM) override;
  NS_IMETHOD GetAdapterDriverVersion(nsAString & aAdapterDriverVersion) override;
  NS_IMETHOD GetAdapterDriverDate(nsAString & aAdapterDriverDate) override;
  NS_IMETHOD GetAdapterDescription2(nsAString & aAdapterDescription) override;
  NS_IMETHOD GetAdapterDriver2(nsAString & aAdapterDriver) override;
  NS_IMETHOD GetAdapterVendorID2(nsAString & aAdapterVendorID) override;
  NS_IMETHOD GetAdapterDeviceID2(nsAString & aAdapterDeviceID) override;
  NS_IMETHOD GetAdapterSubsysID2(nsAString & aAdapterSubsysID) override;
  NS_IMETHOD GetAdapterRAM2(nsAString & aAdapterRAM) override;
  NS_IMETHOD GetAdapterDriverVersion2(nsAString & aAdapterDriverVersion) override;
  NS_IMETHOD GetAdapterDriverDate2(nsAString & aAdapterDriverDate) override;
  NS_IMETHOD GetIsGPU2Active(bool *aIsGPU2Active) override;

  virtual nsresult Init() override;

#ifdef DEBUG
  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_NSIGFXINFODEBUG
#endif

protected:
  virtual ~GfxInfo() {};

  virtual const nsTArray<GfxDriverInfo>& GetGfxDriverInfo() override;

private:
  nsCString mVendor;
  nsCString mRenderer;
  nsCString mVersion;
  nsCString mAdapterDescription;
};

} // namespace widget
} // namespace mozilla

#endif /* __GfxInfoGTK_h__ */
