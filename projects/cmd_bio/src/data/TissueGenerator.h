#ifndef BIOGEARS_TISSUE_GENERATOR_H
#define BIOGEARS_TISSUE_GENERATOR_H

//**********************************************************************************
//Copyright 2015 Applied Research Associates, Inc.
//Licensed under the Apache License, Version 2.0 (the "License"); you may not use
//this file except in compliance with the License.You may obtain a copy of the License
//at :
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under
//the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
//CONDITIONS OF ANY KIND, either express or implied.See the License for the
//specific language governing permissions and limitations under the License.
//**************************************************************************************

#include <string>
#include <vector>

#include <biogears/schema/biogears/BioGearsConfiguration.hxx>
#include "CSVToXMLConvertor.h"
namespace biogears
{

  struct Tissue
  {

  };

  class TissueGenerator : public CSVToXMLConvertor
  {
  public:
    TissueGenerator(std::string path);
    ~TissueGenerator() override;

    bool parse() override;
    bool save() const override;
    void print() const override;
  protected:
    bool process(const std::vector<std::vector<std::string>>& data);
  private:
    std::vector<Tissue> _input;
    std::vector<mil::tatrc::physiology::datamodel::BioGearsConfigurationData> _Tissues;
  };
} //namespace biogears

#endif //BIOGEARS_TISSUE_GENERATOR_H