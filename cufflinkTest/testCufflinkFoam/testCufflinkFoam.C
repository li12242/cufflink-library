/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright held by original author
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Application
    testCufflinkFoam

Description
    Solves a simple Laplace equation, e.g. for thermal diffusion in a solid.
    Uses timers for some testing and benchmarking in cufflink.

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{

#   include "setRootCase.H"

#   include "createTime.H"
#   include "createMesh.H"
#   include "createFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    Info<< "\nCalculating temperature distribution\n" << endl;

    for (runTime++; !runTime.end(); runTime++)
    {
        Info<< "Time = " << runTime.timeName() << nl << endl;

        Info<< "PreSolveTime = " << runTime.elapsedCpuTime() << " s"
            << "  PreSolveClockTime = " << runTime.elapsedClockTime() << " s"
            << nl << endl; 

            solve
            (
//                fvm::ddt(T) - fvm::laplacian(DT, T)  //time dependent solution
               fvm::laplacian(DT, T)
            );

        Info<< "PostSolveTime = " << runTime.elapsedCpuTime() << " s"
            << "  PostSolveClockTime = " << runTime.elapsedClockTime() << " s"
            << nl << endl;            

        runTime.write();

        Info<< "TotalExecutionTime = " << runTime.elapsedCpuTime() << " s"
            << "  TotalClockTime = " << runTime.elapsedClockTime() << " s"
            << nl << endl;
    }

    Info<< "End\n" << endl;

    return(0);
}


// ************************************************************************* //
