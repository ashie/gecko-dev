/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef _nsPluginNativeWindowGdk_h_
#define _nsPluginNativeWindowGdk_h_

#include "nsPluginNativeWindow.h"
#include "npapi.h"
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#ifdef MOZ_X11
#include <gdk/gdkx.h>
#if (GTK_MAJOR_VERSION == 3)
#include <gtk/gtkx.h>
#else
#include "gtk2xtbin.h"
#endif
#include "mozilla/X11Util.h"
#else
typedef unsigned long XID;
#endif

class nsPluginNativeWindowGtk : public nsPluginNativeWindow {
public:
  nsPluginNativeWindowGtk();
  virtual ~nsPluginNativeWindowGtk();

  virtual nsresult CallSetWindow(RefPtr<nsNPAPIPluginInstance> &aPluginInstance);
#ifdef MOZ_X11
  nsresult CreateXEmbedWindow(bool aEnableXtFocus);
#endif
  void SetAllocation();

  XID GetWindow() const
  {
    return static_cast<XID>(reinterpret_cast<uintptr_t>(window));
  }

private:
  void SetWindow(XID aWindow)
  {
    window = reinterpret_cast<void*>(static_cast<uintptr_t>(aWindow));
  }

  NPSetWindowCallbackStruct mWsInfo;
  /**
   * Either a GtkSocket or a special GtkXtBin widget (derived from GtkSocket)
   * that encapsulates the Xt toolkit within a Gtk Application.
   */
  GtkWidget* mSocketWidget;
#if (MOZ_WIDGET_GTK == 2)
  nsresult  CreateXtWindow();
#endif
};

#endif
