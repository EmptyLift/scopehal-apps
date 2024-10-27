/***********************************************************************************************************************
*                                                                                                                      *
* ngscopeclient                                                                                                        *
*                                                                                                                      *
* Copyright (c) 2012-2024 Andrew D. Zonenberg and contributors                                                         *
* All rights reserved.                                                                                                 *
*                                                                                                                      *
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the     *
* following conditions are met:                                                                                        *
*                                                                                                                      *
*    * Redistributions of source code must retain the above copyright notice, this list of conditions, and the         *
*      following disclaimer.                                                                                           *
*                                                                                                                      *
*    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the       *
*      following disclaimer in the documentation and/or other materials provided with the distribution.                *
*                                                                                                                      *
*    * Neither the name of the author nor the names of any contributors may be used to endorse or promote products     *
*      derived from this software without specific prior written permission.                                           *
*                                                                                                                      *
* THIS SOFTWARE IS PROVIDED BY THE AUTHORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED   *
* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL *
* THE AUTHORS BE HELD LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES        *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR       *
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE       *
* POSSIBILITY OF SUCH DAMAGE.                                                                                          *
*                                                                                                                      *
***********************************************************************************************************************/

/**
	@file
	@author Andrew D. Zonenberg
	@brief Declaration of FunctionGeneratorDialog
 */
#ifndef FunctionGeneratorDialog_h
#define FunctionGeneratorDialog_h

#include "Dialog.h"
#include "RollingBuffer.h"
#include "Session.h"

class FunctionGeneratorChannelUIState
{
public:
	bool m_outputEnabled;

	std::string m_amplitude;
	float m_committedAmplitude;

	std::string m_offset;
	float m_committedOffset;

	std::string m_dutyCycle;
	float m_committedDutyCycle;

	std::string m_frequency;
	float m_committedFrequency;

	std::string m_riseTime;
	float m_committedRiseTime;

	std::string m_fallTime;
	float m_committedFallTime;

	int m_impedanceIndex;

	int m_shapeIndex;
	std::vector<FunctionGenerator::WaveShape> m_waveShapes;
	std::vector<std::string> m_waveShapeNames;
};

class FunctionGeneratorDialog : public Dialog
{
public:
	FunctionGeneratorDialog(std::shared_ptr<SCPIFunctionGenerator> gen, std::shared_ptr<FunctionGeneratorState> sessionState, Session* session);
	virtual ~FunctionGeneratorDialog();

	virtual bool DoRender();

	std::shared_ptr<SCPIFunctionGenerator> GetGenerator()
	{ return m_generator; }

protected:
	void DoChannel(size_t i);

	///@brief Session handle so we can remove the PSU when closed
	Session* m_session;

	///@brief The generator we're controlling
	std::shared_ptr<SCPIFunctionGenerator> m_generator;

	///@brief Current channel stats, live updated
	std::shared_ptr<FunctionGeneratorState> m_state;

	///@brief UI state for each channel
	std::vector<FunctionGeneratorChannelUIState> m_uiState;

	///@brief Output impedances
	std::vector<FunctionGenerator::OutputImpedance> m_impedances;

	///@brief Human readable description of each element in m_impedances
	std::vector<std::string> m_impedanceNames;

};



#endif
