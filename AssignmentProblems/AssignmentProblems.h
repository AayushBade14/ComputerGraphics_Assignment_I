//-----------------------------------------------------------------------------
//  
//  Name: AssignmentProblems.h
//
//  Desc: Declares the interface for assignment problems - different assignment
//  problems must be implemented in an implementation of this interface
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

class AssignmentProblems
{

  public:

    virtual ~AssignmentProblems() = default;

    virtual void Run() = 0;
};

