/*
 * Copyright (C) 2005-2017 Centre National d'Etudes Spatiales (CNES)
 *
 * This file is part of Orfeo Toolbox
 *
 *     https://www.orfeo-toolbox.org/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef otbWrapperAddProcessToWatchEvent_h
#define otbWrapperAddProcessToWatchEvent_h

#include "itkEventObject.h"
#include "itkProcessObject.h"
#include "OTBApplicationEngineExport.h"

namespace otb
{
namespace Wrapper
{

/** \class AddProcessToWatchEvent
 *  \brief This class implements an event, storing a pointer to
 *  itk::ProcessObject and a string describing the process.
 *
 *
 * \ingroup OTBApplicationEngine
 */
class OTBApplicationEngine_EXPORT AddProcessToWatchEvent: public itk::EventObject
{
public:

  typedef AddProcessToWatchEvent Self;
  typedef itk::EventObject       Superclass;

  AddProcessToWatchEvent(){}
  AddProcessToWatchEvent(const Self& s) :itk::EventObject(s){};
  ~AddProcessToWatchEvent() ITK_OVERRIDE {}

  /** Set the process to watch */
  virtual void SetProcess(itk::ProcessObject * process)
  {
    m_Process = process;
  }

  /** Get the process to watch */
  virtual itk::ProcessObject * GetProcess() const
  {
    return m_Process;
  }

  /** Set the process description */
  virtual void SetProcessDescription(const std::string desc)
  {
    m_ProcessDescription = desc;
  }

  /** Get the process description */
  virtual  std::string GetProcessDescription() const
  {
    return m_ProcessDescription;
  }

  /**  */
  itk::EventObject* MakeObject() const ITK_OVERRIDE
  {
    return new Self;
  }

  const char* GetEventName() const ITK_OVERRIDE
  {
    return "AddProcess";
  }
  bool CheckEvent(const itk::EventObject* e) const ITK_OVERRIDE
  {
    return dynamic_cast<const Self*>(e);
  }

private:
  itk::ProcessObject::Pointer m_Process;
  std::string                 m_ProcessDescription;
};

}
}

#endif
