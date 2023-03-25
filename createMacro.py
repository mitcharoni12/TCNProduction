import numpy as np
import matplotlib.pyplot as plt
import time

def neutronFlux(energy):
    falt = 4.833
    fBYSD = 0.82375
    b1 = 0.3500
    b2 = 0.4106
    g1 = 2.1451
    g2 = -0.6670
    c1 = 0.000001006
    c2 = 0.001011

    flux = falt * fBYSD * energy * (c1 * np.exp(-b1 * np.log(energy) * np.log(energy) + g1 * np.log(energy)) + c2 * np.exp(-b2 * np.log(energy) * np.log(energy) + g2 * np.log(energy)))\
    
    return flux


file = open("Test.in", "w")

#Code to make macrofile for setting up the particle source I need
file.write("/run/initialize\n\n")

file.write("/random/setSeeds " + str(time.time()) + " 35\n\n") #for seeding random number generator

file.write("/gps/verbose 0\n")
file.write("/gps/particle neutron\n\n")

file.write("/gps/pos/type Plane\n")
file.write("/gps/pos/rot1 1 0 0\n")
file.write("/gps/pos/rot2 0 1 0\n\n")

file.write("/gps/pos/shape Square\n")
file.write("/gps/pos/centre 0.0 0.0 0.6 m\n")
file.write("/gps/pos/halfx 0.5 cm\n")
file.write("/gps/pos/halfy 0.5 cm\n\n")

file.write("/gps/ene/type User\n")
file.write("/gps/hist/type energy\n\n")

#Calculate the weights to send into the histogram for geant4
E1min = 5
E1Max = 50
delta1 = (E1Max-E1min) / 250
energiesE1 = np.linspace(E1min, E1Max, 250)

E2min = 50
E2Max = 200
delta2 = (E2Max-E2min) / 250
energiesE2 = np.linspace(E2min+delta2, E2Max, 250)

E3min = 200
E3Max = 1000
delta3 = (E3Max-E3min) / 250
energiesE3 = np.linspace(E3min + delta3, E3Max, 250)

E4min = 1000
E4Max = 10000
delta4 = (E4Max-E4min) / 250
energiesE4 = np.linspace(E4min + delta4, E4Max, 250)

fluxesE1 = neutronFlux(energiesE1) * delta1
fluxesE2 = neutronFlux(energiesE2) * delta2
fluxesE3 = neutronFlux(energiesE3) * delta3
fluxesE4 = neutronFlux(energiesE4) * delta4

file.write("/gps/hist/point 4.8 0\n")
for i in range (0, 250):
    file.write("/gps/hist/point "+ str(energiesE1[i])+ " "+ str(fluxesE1[i])+ "\n")

for i in range (0, 250):
    file.write("/gps/hist/point "+ str(energiesE2[i])+ " "+ str(fluxesE2[i])+ "\n")

for i in range (0, 250):
    file.write("/gps/hist/point "+ str(energiesE3[i])+ " "+ str(fluxesE3[i])+ "\n")

for i in range (0, 250):
    file.write("/gps/hist/point "+ str(energiesE4[i])+ " "+ str(fluxesE4[i])+ "\n")
file.write("\n")
#plt.plot(energies, fluxes)
#plt.xscale("log")
#plt.show()

file.write("/run/beamOn 10000\n")

file.close()