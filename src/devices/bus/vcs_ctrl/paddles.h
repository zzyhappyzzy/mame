// license:BSD-3-Clause
// copyright-holders:Curt Coder
/**********************************************************************

    Atari Video Computer System analog paddles emulation

**********************************************************************/

#pragma once

#ifndef __VCS_PADDLES__
#define __VCS_PADDLES__

#include "emu.h"
#include "ctrl.h"



//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

// ======================> vcs_paddles_device

class vcs_paddles_device : public device_t,
							public device_vcs_control_port_interface
{
public:
	// construction/destruction
	vcs_paddles_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

	// optional information overrides
	virtual ioport_constructor device_input_ports() const override;

protected:
	// device-level overrides
	virtual void device_start() override;

	// device_vcs_control_port_interface overrides
	virtual uint8_t vcs_joy_r() override;
	virtual uint8_t vcs_pot_x_r() override;
	virtual uint8_t vcs_pot_y_r() override;

	virtual bool has_pot_x() override { return true; }
	virtual bool has_pot_y() override { return true; }

private:
	required_ioport m_joy;
	required_ioport m_potx;
	required_ioport m_poty;
};


// device type definition
extern const device_type VCS_PADDLES;


#endif
