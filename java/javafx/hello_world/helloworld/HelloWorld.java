package helloworld;
 
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
 
public class HelloWorld extends Application {
    
    @Override
    public void start(Stage primaryStage) {
        // UI to show/clear a hello world message
        Label lbl = new Label();
        Button btn = new Button();
        btn.setText("Say 'Hello World'");
        btn.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent event) {
                lbl.setText("Hello World!");
            }
        });
        Button clr = new Button("Clear");
        clr.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent event) {
                lbl.setText("");
            }
        });
        
        // UI to show system information
        Label sysInfoLbl = new Label();
        Button sysInfoBtn = new Button("get versions");
        sysInfoBtn.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent event) {
                String javaVersion = System.getProperty("java.version");
                String javafxVersion = System.getProperty("javafx.version");
                sysInfoLbl.setText("JavaFX " + javafxVersion + ", running on Java " + javaVersion + ".");
            }
        });

        // container for all UI elements
        StackPane root = new StackPane();
        
        VBox vbox = new VBox();
        vbox.setSpacing(8); // Gap between nodes

        // first UI group (horizontal): hello world button, clear button, label
        HBox h1 = new HBox();
        h1.setSpacing(8);
        h1.getChildren().addAll(btn, clr, lbl);

        /* second UI group (vertical):
         *      first UI group
         *      get system info button
         *      label to display system info
         */
        vbox.getChildren().addAll(h1, sysInfoBtn,sysInfoLbl);
        
        // add both UI groups to a parent Pane
        root.getChildren().add(vbox);

        // create a Pane container
        Scene scene = new Scene(root, 300, 250);
        // set "stage" (window) attributes
        primaryStage.setTitle("Hello JavaFX!");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
