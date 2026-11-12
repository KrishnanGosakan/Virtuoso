#pragma once
#ifndef ELASTIC_TLB_SUBSYSTEM_H
#define ELASTIC_TLB_SUBSYSTEM_H

#include "elastic_tlb.h"
#include "tlb_prefetcher_base.h"
#include "pagesize_predictor_base.h"

namespace ParametricDramDirectoryMSI
{

	typedef std::vector<std::vector<ElasticTLB *>> ElasticTLBSubsystem;

	class ElasticTLBHierarchy
	{

	private:
		ElasticTLBSubsystem tlbLevels;
		ElasticTLBSubsystem data_path;
		ElasticTLBSubsystem instruction_path;
		PageSizePredictorBase *page_size_predictor;
		int numLevels;
		// int *page_size_list;
		int page_sizes;
		int numTLBsPerLevel;

		std::vector<std::vector<ComponentLatency>> tlb_latencies;

	public:
		bool prefetch_enabled;
		ElasticTLBHierarchy(String mmu_name, Core *core, MemoryManagerBase *memory_manager, ShmemPerfModel *shmem_perf_model);
		~ElasticTLBHierarchy();
		ElasticTLBSubsystem getTLBSubsystem() { return tlbLevels; }
		ElasticTLBSubsystem getDataPath() { return data_path; }
		ElasticTLBSubsystem getInstructionPath() { return instruction_path; }
		bool isPrefetchEnabled() { return prefetch_enabled; }
		int getNumLevels() { return numLevels; }
		int predictPagesize(IntPtr eip);
		void updatePageSizePredictor(IntPtr virtual_address, int page_size);
		void predictionResult(IntPtr eip, bool success);
	};

}

#endif
