# 5GTQ: QoS-Aware 5G-TSN Simulation Framework (VTC Fall 2023 Paper)

5GTQ Framework of the publication: 5GTQ: QoS-Aware 5G-TSN Simulation Framework

To cite our work, please use the following BibTex code:

```
@INPROCEEDINGS{10333533,
  author={Debnath, Rubi and Akinci, Mustafa Selman and Ajith, Devika and Steinhorst, Sebastian},
  booktitle={2023 IEEE 98th Vehicular Technology Conference (VTC2023-Fall)}, 
  title={5GTQ: QoS-Aware 5G-TSN Simulation Framework}, 
  year={2023},
  volume={},
  number={},
  pages={1-7},
  doi={10.1109/VTC2023-Fall60731.2023.10333533}}
```

# Regular Feature Updates
We are working on introducing new features in the 5GTQ framework to support the specific scheduling features of the 5G-TSN simulation. 
All the updates will be mentioned in the README file.

# Installation

## Command line

Download and install OMNeT++ 6.0.x, then:

    git clone --recurse-submodules git@github.com:tum-esi/5GTQ.git
    cd 5GTQ
    source setenv
    make     # wait for the build to finish
    cd tsnfivegcomm/simulations/globecom/Scenario_One/paper/TC1
    tsn5g scenario222.ini

## IDE

First clone the repo, then start the IDE:

    git clone --recurse-submodules git@github.com:tum-esi/5GTQ.git
    cd 5GTQ
    opp_ide

- Select the 5GTQ directory as a new workspace
- Import all projects (inet, Simu5G, tsnfivegcomm)
- Build the **tsnfivegcomm** project (which will also build inet and Simu5G)
- Go to the `simulations` directory and select a scenario and then select run (or debug)


## Important 

5GTQ framework is under continuous development: new features are added, bugs are corrected, and so on. 
We cannot assert that the implementation will work fully according to the standard and the specifications. 
YOU ARE RESPONSIBLE YOURSELF TO MAKE SURE THAT THE MODELS YOU USE IN YOUR SIMULATIONS WORK CORRECTLY, AND YOU ARE GETTING VALID RESULTS.


