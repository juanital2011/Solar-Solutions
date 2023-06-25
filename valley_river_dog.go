package main

import "fmt"

// SolarSolutions is a package to calculate solar energy needs for a given area
type SolarSolutions struct {
	// Dimensions of the area to be covered in square meters.
	Area float64
	// Average number of kWh of energy needed per month
	KWHNeeded float64
	// Number of sunny hours per day in that area
	SunshineHours float64
	// Number of panels necessary for solar solution
	PanelNumber int
}

// CalculateSolution is a function to calculate the solar solutions
func (ss *SolarSolutions) CalculateSolution() float64 {
	// Calculate total kWh produced per month
	kWhperMonth := ss.SunshineHours * ss.PanelNumber * 30
	// Calculate how many kWh are needed
	kWhNeeded := ss.KWHNeeded * 30
	// Calculate how many percent of the total needs are being met
	percentMet := kWhperMonth / kWhNeeded * 100
	return percentMet
}

// CalculatePanelNumber is a function to calculate the number of solar panels necessary for a given area
func (ss *SolarSolutions) CalculatePanelNumber() int {
	panelNumber := (ss.KWHNeeded * 30) / (ss.SunshineHours * 30)
	return int(panelNumber)
}

func main() {
	// Instantiate SolarSolutions struct
	solarSolutions := SolarSolutions{
		Area:         15000,
		KWHNeeded:    1000,
		SunshineHours: 6.0,
	}

	// Calculate the number of solar panels necessary
	panels := solarSolutions.CalculatePanelNumber()
	fmt.Println("Number of panels needed:", panels)

	// Set the solar solutions panel number
	solarSolutions.PanelNumber = panels

	// Calculate the percent of needs met by the solar system
	percentMet := solarSolutions.CalculateSolution()
	fmt.Printf("Percent of monthly needs met by solar: %.2f%%\n", percentMet)
}