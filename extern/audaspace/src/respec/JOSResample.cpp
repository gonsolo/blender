/*******************************************************************************
 * Copyright 2009-2016 Jörg Müller
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#include "respec/JOSResample.h"
#include "respec/JOSResampleReader.h"

AUD_NAMESPACE_BEGIN

JOSResample::JOSResample(std::shared_ptr<ISound> sound, DeviceSpecs specs, ResampleQuality quality) :
		SpecsChanger(sound, specs), m_quality(quality)
{
}

std::shared_ptr<IReader> JOSResample::createReader()
{
	return std::shared_ptr<IReader>(new JOSResampleReader(getReader(), m_specs.rate, m_quality));
}

AUD_NAMESPACE_END
