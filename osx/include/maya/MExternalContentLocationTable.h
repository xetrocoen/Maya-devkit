#ifndef _MExternalContentLocationTable
#define _MExternalContentLocationTable
//-
// ==========================================================================
// Copyright (C) 2012 Autodesk, Inc., and/or its licensors.  All
// rights reserved.
//
// The coded instructions, statements, computer programs, and/or related
// material (collectively the "Data") in these files contain unpublished
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its
// licensors,  which is protected by U.S. and Canadian federal copyright law
// and by international treaties.
//
// The Data may not be disclosed or distributed to third parties or be
// copied or duplicated, in whole or in part, without the prior written
// consent of Autodesk.
//
// The copyright notices in the Software and this entire statement,
// including the above license grant, this restriction and the following
// disclaimer, must be included in all copies of the Software, in whole
// or in part, and all derivative works of the Software, unless such copies
// or derivative works are solely in the form of machine-executable object
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE,
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES.
// ==========================================================================

#if defined __cplusplus

#include <maya/MTypes.h>

// ****************************************************************************
// FORWARD DECLARATIONS


class MString;
class MStatus;

//! \ingroup OpenMaya
/*! \brief This is a table of the all the external content locations for a given
	MPxNode.

	It is a subset of the information contained in MExternalContentInfo: it has
	as many entries, but each entry only states the key and location.

	While MExternalContentInfoTable is meant to query external content from a
    MPxNode, MExternalContentLocationTable is meant to pass modified
    locations back to the MPxNode.

	Key: Same as for MExternalContentInfoTable.

    Value: New location of the content for this entry (path, URI, ...).
*/
class OPENMAYA_EXPORT MExternalContentLocationTable
{
public:
	MExternalContentLocationTable();
	~MExternalContentLocationTable();
	
	MStatus addEntry( const MString& key, const MString& location );
	
BEGIN_NO_SCRIPT_SUPPORT:
	//!	NO SCRIPT SUPPORT
	MStatus getEntry( unsigned int index, MString& key, MString& location ) const;
	//!	NO SCRIPT SUPPORT
	MStatus getLocation( const MString& key, MString& location ) const;
END_NO_SCRIPT_SUPPORT:	
	
	unsigned int length() const;
	
private:
	friend struct THdependNodeTemplateUtil;	
	friend class MPxNode;
	friend class MFnDependencyNode;

	void* getData() const;
	MExternalContentLocationTable( const MExternalContentLocationTable& );
	MExternalContentLocationTable& operator=( const MExternalContentLocationTable& );
	MExternalContentLocationTable( const void* const data );	
	
	void* api_data;
};

#endif /* __cplusplus */
#endif /* _MExternalContentLocationTableTable */
