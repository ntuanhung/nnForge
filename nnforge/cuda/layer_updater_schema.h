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

#include "layer_updater_cuda.h"
#include "../layer.h"
#include "../layer_data.h"
#include "../layer_configuration_specific.h"
#include "../nn_types.h"

#include "cuda_running_configuration.h"

#include <utility>
#include <memory>
#include <vector>
#include <string>
#include <boost/uuid/uuid.hpp>

namespace nnforge
{
	namespace cuda
	{
		class layer_updater_schema
		{
		public:
			typedef nnforge_shared_ptr<layer_updater_schema> ptr;
			typedef nnforge_shared_ptr<const layer_updater_schema> const_ptr;

			virtual ~layer_updater_schema();

			nnforge_shared_ptr<layer_updater_schema> create(
				layer::const_ptr layer_schema,
				cuda_running_configuration::const_ptr cuda_config) const;

			layer_updater_cuda::ptr create_updater(
				const std::vector<layer_configuration_specific>& input_configuration_specific_list,
				const layer_configuration_specific& output_configuration_specific,
				const std::set<layer_action>& actions) const;

			virtual std::string get_type_name() const = 0;

			// returns the list of buffers defining the schema
			virtual std::vector<cuda_linear_buffer_device::const_ptr> get_schema_buffers() const;

		protected:
			virtual layer_updater_schema::ptr create_specific() const = 0;

			virtual layer_updater_cuda::ptr create_updater_specific(
				const std::vector<layer_configuration_specific>& input_configuration_specific_list,
				const layer_configuration_specific& output_configuration_specific) const = 0;

			layer_updater_schema();

			layer::const_ptr layer_schema;
			cuda_running_configuration::const_ptr cuda_config;

		private:
			layer_updater_schema(const layer_updater_schema&);
			layer_updater_schema& operator =(const layer_updater_schema&);
		};
	}
}
