package helloworld;
 
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Dialog;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import java.awt.*;
import javafx.scene.control.*;
 
public class HelloWorld extends Application
{
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
        
        // Dialog pop up windows
        // from https://stackoverflow.com/questions/26341152/controlsfx-dialogs-deprecated-for-what/32618003#32618003
        Alert info = new Alert(Alert.AlertType.INFORMATION);
        info.initStyle(StageStyle.UTILITY);
        info.setTitle("Information Title");
        info.setHeaderText("Information Header");
        info.setContentText("This is an information dialog.");
        Button infoAlert = new Button("Show information");
        infoAlert.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                info.showAndWait();
            }
        });
        
        Alert warn = new Alert(Alert.AlertType.WARNING);
        warn.initStyle(StageStyle.UTILITY);
        warn.setTitle("Warning Title");
        warn.setHeaderText("Warning Header");
        warn.setContentText("This is a warning dialog.");
        Button warnAlert = new Button("Show warning");
        warnAlert.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                warn.showAndWait();
            }
        });
        
        Alert error = new Alert(Alert.AlertType.ERROR);
        error.initStyle(StageStyle.UTILITY);
        error.setTitle("Error Title");
        error.setHeaderText("Error Header");
        error.setContentText("This is an error dialog.");
        Button errorAlert = new Button("Show error");
        errorAlert.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                error.showAndWait();
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
        
        vbox.getChildren().addAll(infoAlert, warnAlert, errorAlert);
        
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
