/*
 *  Copyright 2011-2015 Maxim Milakov
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#pragma once

#include "layer_testing_schema.h"

namespace nnforge
{
	namespace cuda
	{
		class rgb_to_yuv_convert_layer_testing_schema : public layer_testing_schema
		{
		public:
			rgb_to_yuv_convert_layer_testing_schema();

			virtual ~rgb_to_yuv_convert_layer_testing_schema();

			virtual std::string get_type_name() const;

			virtual std::vector<cuda_linear_buffer_device::const_ptr> get_schema_buffers() const;

		protected:
			virtual layer_testing_schema::ptr create_specific() const;

			virtual layer_tester_cuda::ptr create_tester_specific(
				const std::vector<layer_configuration_specific>& input_configuration_specific_list,
				const layer_configuration_specific& output_configuration_specific) const;
		};
	}
}
