/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Written (W) 2013 Soumyajit De
 */

#ifndef STORE_SCALAR_AGGREGATOR_H_
#define STORE_SCALAR_AGGREGATOR_H_

#include <shogun/lib/config.h>
#include <shogun/lib/computation/job/JobResultAggregator.h>

namespace shogun
{
class CJobResult;
template<class T> class CScalarResult;

/** @brief Template class that aggregates scalar job results in each
 * submit_result call, finalize then transforms current aggregation into
 * a CScalarResult.
 */
template<class T> class CStoreScalarAggregator : public CJobResultAggregator
{
public:
	/** default constructor, no args */
	CStoreScalarAggregator();

	/** destructor */
	virtual ~CStoreScalarAggregator();

	/** method that submits the result (scalar) of an independent job, and
	 * computes the aggregation with the previously submitted result
	 * @param the result of an independent job
	 */
	virtual void submit_result(CJobResult* result);

	/** method that finalizes the aggregation and computes the result (scalar),
	 * its necessary to call finalize before getting the final result
	 */
	virtual void finalize();

	/** @return object name */
	virtual const char* get_name() const
	{
		return "CStoreScalarAggregator";
	}
private:
	/** the aggregation */
	T m_aggregate;
};

}

#endif // STORE_SCALAR_AGGREGATOR_H_