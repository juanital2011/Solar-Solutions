// Define package
package Solar_Solutions

// Import packages
import android.graphics.Canvas
import android.graphics.Point
import android.content.Context
import android.widget.Toast
import java.util.ArrayList

// Create a data class to track solar panel output
data class SolarPanel(val wattage: Double, val size: Point)

// Create an enum to represent the solar panel orientation
enum class SolarPanelOrientation {
    VERTICAL,
    HORIZONTAL
}

// Create a class to represent a solar array
class SolarArray {
    // Private properties
    private val panels: ArrayList<SolarPanel>

    // Constructor
    constructor(context: Context) {
        // Initialize the array list
        this.panels = ArrayList()

        // Display a toast
        Toast.makeText(context, "Solar array created!", Toast.LENGTH_SHORT).show()
    }

    // Method to add a new solar panel
    fun addPanel(panel: SolarPanel) {
        this.panels.add(panel)
    }

    // Method to draw the solar array
    fun draw(canvas: Canvas) {
        for (panel in this.panels) {
            // Draw solar panel
            canvas.drawRect(panel.size.x, panel.size.y,
                    panel.size.x + panel.size.width,
                    panel.size.y + panel.size.height,
                    paint)
        }
    }
}

// Create a class to represent a solar powered house
class SolarPoweredHouse {
    // Private properties
    private val solarArray: SolarArray

    // Constructor
    constructor(context: Context) {
        // Initialize the solar array
        this.solarArray = SolarArray(context)
    }

    // Method to add a panel to the house
    fun addPanel(panel: SolarPanel) {
        this.solarArray.addPanel(panel)
    }

    // Method to draw the solar powered house
    fun draw(canvas: Canvas) {
        // Draw house
        canvas.drawRect(0, 0, width, height, paint)

        // Draw solar array
        this.solarArray.draw(canvas)
    }
}

// Create a class to represent a solar powered car
class SolarPoweredCar {
    // Private properties
    private val solarPanel: SolarPanel

    // Constructor
    constructor(context: Context, panel: SolarPanel) {
        this.solarPanel = panel

        // Display a toast
        Toast.makeText(context, "Solar powered car created!", Toast.LENGTH_SHORT).show()
    }

    // Method to draw the solar powered car
    fun draw(canvas: Canvas, orientation: SolarPanelOrientation) {
        // Draw car
        canvas.drawRect(0, 0, width, height, paint)

        // Draw solar panel
        if (orientation == SolarPanelOrientation.VERTICAL) {
            canvas.drawRect(0, 0, solarPanel.size.width,
                    solarPanel.size.height, paint)
        } else {
            canvas.drawRect(0, 0, solarPanel.size.height,
                    solarPanel.size.width, paint)
        }
    }
}