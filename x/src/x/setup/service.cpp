/* Copyright 2014-2017 Rsyn
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

// HOW-TO
// To register a step, just include its .h below and add a call to
// "registerService<T>(name)" where T is the service class name and name how
// the service will be referred to.

#include "rsyn/session/Session.h"

// Services
#include "rsyn/phy/PhysicalService.h"
#include "rsyn/model/scenario/Scenario.h"
#include "rsyn/model/timing/Timer.h"
#include "rsyn/model/timing/DefaultTimingModel.h"
#include "rsyn/model/library/LibraryCharacterizer.h"
#include "rsyn/model/routing/RoutingEstimator.h"
#include "rsyn/model/routing/DefaultRoutingEstimationModel.h"
#include "rsyn/model/routing/DefaultRoutingExtractionModel.h"
#include "rsyn/model/routing/RsttRoutingEstimatorModel.h"
#include "rsyn/model/congestion/DensityGrid/DensityGridService.h"
#include "rsyn/io/Report.h"
#include "rsyn/io/Writer.h"
#include "rsyn/io/Graphics.h"
#include "rsyn/io/WebLogger.h"
#include "x/model/DefaultTimingModelWithIdealClock.h"
#include "x/infra/iccad15/Infrastructure.h"
#include "x/jezz/Jezz.h"
#include "x/util/BlockageControl.h"
#include "x/util/NetlistExtractor.h"

// Registration
namespace Rsyn {
void Session::registerServices() {
	registerService<Rsyn::PhysicalService>("rsyn.physical");
	registerService<Rsyn::Scenario>("rsyn.scenario");
	registerService<Rsyn::Timer>("rsyn.timer");
	registerService<Rsyn::DefaultTimingModel>("rsyn.defaultTimingModel");
	registerService<Rsyn::LibraryCharacterizer>("rsyn.libraryCharacterizer");
	registerService<Rsyn::RoutingEstimator>("rsyn.routingEstimator");
	registerService<Rsyn::DefaultRoutingEstimationModel>("rsyn.defaultRoutingEstimationModel");
	registerService<Rsyn::DefaultRoutingExtractionModel>("rsyn.defaultRoutingExtractionModel");
	registerService<Rsyn::RsttRoutingEstimatorModel>("rsyn.RSTTroutingEstimationModel");
	registerService<Rsyn::DensityGridService>("rsyn.densityGrid");
	registerService<Rsyn::Report>("rsyn.report");
	registerService<Rsyn::Writer>("rsyn.writer");
	registerService<Rsyn::Graphics>("rsyn.graphics");
	registerService<Rsyn::WebLogger>("rsyn.webLogger");

	registerService<Jezz>("rsyn.jezz");
	registerService<ICCAD15::DefaultTimingModelWithIdealClock>("rsyn.defaultTimingModelWithIdealClock");
	registerService<ICCAD15::Infrastructure>("ufrgs.ispd16.infra");
	registerService<ICCAD15::BlockageControl>("ufrgs.blockageControl");

	registerService<NetlistExtractor>("rsyn.netlistExtractor");
} // end method
} // end namespace

