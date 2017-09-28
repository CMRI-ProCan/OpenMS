// --------------------------------------------------------------------------
//                   OpenMS -- Open-Source Mass Spectrometry
// --------------------------------------------------------------------------
// Copyright The OpenMS Team -- Eberhard Karls University Tuebingen,
// ETH Zurich, and Freie Universitaet Berlin 2002-2017.
//
// This software is released under a three-clause BSD license:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of any author or any participating institution
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
// For a full list of authors, refer to the file AUTHORS.
// --------------------------------------------------------------------------
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL ANY OF THE AUTHORS OR THE CONTRIBUTING
// INSTITUTIONS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// --------------------------------------------------------------------------
// $Maintainer: Douglas McCloskey $
// $Authors: Douglas McCloskey $
// --------------------------------------------------------------------------

#ifndef OPENMS_ANALYSIS_OPENSWATH_MRMFEATUREQC_H
#define OPENMS_ANALYSIS_OPENSWATH_MRMFEATUREQC_H

#include <OpenMS/KERNEL/MRMFeature.h>
#include <OpenMS/KERNEL/Feature.h>
#include <OpenMS/KERNEL/FeatureMap.h>
#include <OpenMS/FORMAT/QcMLFile.h>

#include <OpenMS/DATASTRUCTURES/String.h>
#include <OpenMS/CONCEPT/LogStream.h>

namespace OpenMS
{

  /**

    @brief The MRMFeatureQC is a class to handle the parameters and options for 
      MRMFeatureFilter. The format is based on the TraML format.

  */
  class OPENMS_DLLAPI MRMFeatureQC :
  {

public:

    //@{
    /// Constructor
    MRMFeatureQC();

    /// Destructor
    ~MRMFeatureQC();
    //@}

    // Members

    // QCs within a component group
    struct ComponentGroupQCs
    {
      // name of the component group
      String component_group_name_; 

      // Feature members
      // retention time
      double rt_l_;
      double rt_u_;
      // intensity
      double intensity_l_;
      double intensity_u_;
      // overall quality
      double overall_quality_l_;
      double overall_quality_u_;

      // Feature MetaValues
      // [featureName,(l,u)]
      std::vector<String,std::pair<double,double>> meta_value_qc_

      // Custom QCs
      int n_heavy_l_;
      int n_heavy_u_;
      int n_light_l_;
      int n_light_u_;
      int n_detecting_l_;
      int n_detecting_u_;
      int n_quantifying_l_;
      int n_quantifying_u_;
      int n_identifying_l_;
      int n_identifying_u_;
      int n_transitions_l_;
      int n_transitions_u_;

      // name of the component
      String component_name_; 
      // name of the component to calculate the ion ratio
      String ion_ratio_pair_name_1_;
      String ion_ratio_pair_name_2_;
      double ion_ratio_l_;
      double ion_ratio_u_;
      // name of the component to calculate the resolution or retention time 
      String resolution_pair_name_; 
      double resolution_l_;
      double resolution_u_;
      double rt_diff_l_;
      double rt_diff_u_;
        
    }

    // QCs for individual components
    struct ComponentQCs
    {
      // name of the component
      String component_name_; 

      // Feature members
      // retention time
      double rt_l_;
      double rt_u_;
      // intensity
      double intensity_l_;
      double intensity_u_;
      // overall quality
      double overall_quality_l_;
      double overall_quality_u_;

      // Feature MetaValues
      std::vector<String,std::pair<double,double>> meta_value_qc_
    }
  };
}

#endif //  OPENMS_ANALYSIS_OPENSWATH_MRMFEATUREQC_H

