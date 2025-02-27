#ifndef INVPANELBASE_H
#define INVPANELBASE_H

#include "cbase.h"
using namespace vgui;
#include <vgui/IVGui.h>
#include <vgui_controls/Frame.h>
#include <game/client/iviewport.h>
#include "vgui_controlgrid.h"

class CInvPanel : public vgui::Frame, public IViewPortPanel
{
public:
	DECLARE_CLASS_SIMPLE(CInvPanel, vgui::Frame); 

	CInvPanel(IViewPort *pViewPort); 	// Constructor
	~CInvPanel(){};				// Destructor

	virtual const char *GetName( void ) { return PANEL_INVENTORY; }
	virtual void SetData(KeyValues *data) {};
	virtual void Reset() {};
	virtual void BeginUpdates();
	virtual void Update();
	virtual bool NeedsUpdate( void ) { return false; }
	virtual bool HasInputElements( void ) { return true; }
	virtual void ShowPanel( bool bShow );

	// both vgui::Frame and IViewPortPanel define these, so explicitly define them here as passthroughs to vgui
	vgui::VPANEL GetVPanel( void ) { return BaseClass::GetVPanel(); }
	virtual bool IsVisible() { return BaseClass::IsVisible(); }
	virtual void SetParent( vgui::VPANEL parent ) { BaseClass::SetParent( parent ); }
	virtual void OnThink();
	virtual void OnCommand(const char *command);
	void OnClose();
	void OnKeyCodeTyped(KeyCode code);
protected:
	//VGUI overrides:
	IViewPort *m_pViewPort;
	ControlGrid *InvSubPanel;
	ButtonCode_t m_iInvKey;


private:
	//Other used VGUI control Elements:
	int update_counter;
	Label *pCarryWeightLabel;
};

#endif
