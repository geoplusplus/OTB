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

#ifndef otbWrapperApplicationHtmlDocGenerator_h
#define otbWrapperApplicationHtmlDocGenerator_h

#include "otbWrapperApplication.h"

namespace otb
{
namespace Wrapper
{
/** \class ApplicationHtmlDocGenerator
 *  \brief This class generates the documentation of a class using the
 *  class doc attributes.
 *
 * \ingroup OTBApplicationEngine
 */

class OTBApplicationEngine_EXPORT ApplicationHtmlDocGenerator
{
public:
 /** Standard class typedef */
  typedef ApplicationHtmlDocGenerator   Self;

  /** Constructor */
  ApplicationHtmlDocGenerator();

  /** Destructor */
  virtual ~ApplicationHtmlDocGenerator();

  /** Generate and save the documentation in the file pointed by \a filename.
   * \param app : application pointer
   * \param filename : path to the file 
   * \param showKey : if \c true will display command line example, 
   * default is \c false  
   */
  static void GenerateDoc( const Application::Pointer app, const std::string & filename, const bool showKey = false );
  /** Generate the documentation.
   * \param app : application pointer
   * \param val : string that will receive the documentation
   * \param showKey : if \c true will display command line example, 
   * default is \c false  
   */
  static void GenerateDoc( const Application::Pointer app, std::string & val, const bool showKey = false);

protected:

  /** Get the parameter description of one parameter.
   * \param showKey : if sets to \c true display the full key 
   * (parent.group.key) , default is \c false
   */
  static void GetDocParameters( const Application::Pointer app, std::string & val, const bool showKey = false );

  /** generate the documentation associated to a group.
   * \param showKey : if sets to \c true display the full key 
   * (parent.group.key) , default is \c false
   */
  static void GetDocParameterGroup( const Application::Pointer app, std::string & val, const std::string & key, const bool showKey = false );

  /** generate the documentation associated to a choice.
   * \param showKey : if sets to \c true display the full key 
   * (parent.group.key) , default is \c false
   */
  static void GetDocParameterChoice( const Application::Pointer app, std::string & val, const std::string & key, const bool showKey = false );


private:
  ApplicationHtmlDocGenerator(const ApplicationHtmlDocGenerator &); //purposely not implemented
  void operator =(const ApplicationHtmlDocGenerator&); //purposely not implemented

}; // End class InputImage Parameter

} // End namespace Wrapper
} // End namespace otb

#endif
