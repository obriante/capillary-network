/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2015 Universita' Mediterranea di Reggio Calabria (UNIRC)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Orazio Briante <orazio.briante@unirc.it>
 */
#ifndef MODEL_ENERGY_CONTROLLER_H_
#define MODEL_ENERGY_CONTROLLER_H_

#include "capillary-controller.h"

#include <ns3/capillary-mac.h>
#include <ns3/node.h>
#include <ns3/ptr.h>


namespace ns3 {
/*
 *
 */
class EnergyController : public CapillaryController
{
public:
  EnergyController ();
  virtual ~EnergyController ();

  static TypeId GetTypeId (void);


  virtual void SetNode (Ptr<Node> node);
  virtual void SetMac (Ptr<CapillaryMac> mac);
  virtual Ptr<Node> GetNode (void) const;
  virtual Ptr<CapillaryMac> GetMac (void) const;
  virtual Time GetOffTime (void);

  double GetMaxThreshold () const;
  void SetMaxThreshold (double maxThreshold);
  double GetMinThreshold () const;
  void SetMinThreshold (double minThreshold);

protected:
  virtual void DoInitialize (void);
  virtual void DoDispose (void);

private:
  Ptr<Node> m_node;
  Ptr<CapillaryMac> m_mac;

  double m_maxThreshold;
  double m_minThreshold;
  Time m_maxToff;

  TracedValue<Time> m_Toff;

  Time m_lastUpdate;
  double m_lastConsumption;
  double m_lastHarvested;

};

} /* namespace ns3 */

#endif /* MODEL_ENERGY_CONTROLLER_H_ */